import java.io.*;
import java.util.HashMap;
import java.util.LinkedList;

public class HuffmanEncoder implements HuffmanCoding {


    //this will store all a linkedlist of the value and its corresponding code
    LinkedList<nodeCodes> codes=new LinkedList<>();

    //this will store value of character and frequency, the key being the value fo character
    HashMap<Integer, Integer> hash = new HashMap<>();


    private LinkedList <HuffNode> huffTree = new LinkedList<HuffNode>();



    public LinkedList <HuffNode> getHuffTree(){

        return this.huffTree;
    }


    public void setHuffTree(LinkedList <HuffNode> tree){

        this.huffTree=tree;

    }

    public String getFrequencies(File inputFile) throws FileNotFoundException {

        String frequencies = "";

        BufferedReader scanner = new BufferedReader(new FileReader(inputFile));


        //bufferreader reads and stores each line in String lineText
        while (true) {

            String lineText = "";
            try {
                lineText = scanner.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }

            if (lineText == null) {
                break;
            }
            for (int i = 0; i < lineText.length(); i++) {
                char c = lineText.charAt(i);
                if (c != '\n') {
                    // Increment existing value in HashMap.
                    int value = hash.getOrDefault((int) c, 0);
                    hash.put((int) c, value + 1);
                }
            }
        }

        try{
            // Close object.
            scanner.close();
        }


        catch (IOException e) {
            e.printStackTrace();
        }


        // Stores values of all keys from hashmap to String frequencies.
        for (int key : hash.keySet()) {
            //System.out.println((char) key + "| " + hash.get(key));
            frequencies = frequencies+(char) key + "| " + hash.get(key)+"\n";

        }

        return frequencies;
    }



    public HuffTree buildTree(File inputFile) throws FileNotFoundException, Exception {

        //this LinkedList will hold "HuffNode" objects which contains the left child, right child, weight and value from hashmap "hash"
        LinkedList<HuffNode> hNodes= new LinkedList<>();



        //makes the hash map for all the characters
        getFrequencies(inputFile);

        //goes through the hash map, creates HuffNodes with corresponding attributes from the hash map and makes the left and right child nulls
        for (int key : hash.keySet()) {

            HuffNode x = new HuffNode((char)key, null, null, hash.get(key));
            hNodes.add(x);

        }

        //sorts the LinkedList of HuffNodes
        sortList(hNodes);

        //have to double size of loop because ListList divides by half when i make tree
        int max = hNodes.size()*2;

        for (int i = 0; i!=max;i++){

            //when we have one node (master Node) then break loop
            if(hNodes.size()==1){

                break;
            }

            //takes weight from first node and second node and combines them for parent node
            int lw=hNodes.get(0).getWeight();
            int rw=hNodes.get(1).getWeight();
            int tWeight=rw+lw;

            //removes first to nodes and combines the nodes into  one node
            HuffNode newNode = new HuffNode('\0', hNodes.removeFirst(),hNodes.removeFirst(), tWeight);

            //adds new node to the HuffNodes LinkedList
            hNodes.add(newNode);

            //sort the LinkedList
            sortList(hNodes);


        }

        //create a HuffTree object and return it
        HuffTree hTree = new HuffTree(hNodes);


        hash.clear();
        return hTree;
    }

    public String encodeFile(File inputFile, HuffTree huffTree) throws FileNotFoundException {

        codes.clear();

        String code = "";

        BufferedReader reader = new BufferedReader(new FileReader(inputFile));

        //this will loop goes through the text file and store all the characters in string lineText
        while (true) {

            String lineText = "";
            try {
                lineText = reader.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }

            if (lineText == null) {
                break;
            }

            //this method will get the codes for all the characters and insert them in a linked list of nodeCodes called codes in which each node holds the character and corresponding code in huffman tree
            assignHuffmanCodeValues(huffTree.getHuffTree().get(0));

            //this method will read each character in lineText which holds all the text of the document and traverses through the linkedlist finding which node corresponds to the charcater in text
            //once the value is found, get its code and concatanate it to code which will then be returned at the end.
            for (int i = 0; i < lineText.length(); i++) {
                char c = lineText.charAt(i);
                for(int j = 0; j<codes.size();j++){

                    if (codes.get(j).getValue()==c){
                        code =code+codes.get(j).getCode();

                    }

                }
            }
        }


        return code;

    }


    public String decodeFile(String code, HuffTree huffTree) throws Exception {

        char newCode = '\0';

        String c = "";
        String decoded = "";


        //this method traverses through the string of coed outputted from encode
        //the second for lopp traverses though a linkedlist that contains the codes and value for each character in text
        //once a match is found, concatante to decode string and clear c so a new code can be found
        for (int i = 0; i < code.length(); i++) {
            newCode = code.charAt(i);
            c = c + Character.toString(newCode);


            for (int j = 0; j < codes.size(); j++) {

                if (codes.get(j).getCode().equals(c)) {
                    decoded = decoded + (char)codes.get(j).getValue();
                    c = "";

                }

            }
        }



        codes.clear();
        return decoded;

    }

    public String traverseHuffmanTree (HuffTree huffTree) throws Exception {

        //assigns codes in linked list called codes with its corresponding character value
        assignHuffmanCodeValues(huffTree.getHuffTree().get(0));
        String print = "";

        //traverses though linklist and prints it out
        for (int i = 0; i != codes.size(); i++) {

            print = print  + ((char) codes.get(i).getValue() + "| " + codes.get(i).getCode() + "\n");

        }

        hash.clear();
        codes.clear();

        return print;
    }


    private void assignHuffmanCodeValues(HuffNode node)
    {
        // Iterate though the left sub tree
        assignHuffmanCodeValues(node.getLeft(), "0");

        // Iterate though the right sub tree
        assignHuffmanCodeValues(node.getRight(), "1");
    }
    private void assignHuffmanCodeValues(HuffNode node, String code)
    {

        // If this node has a character value, assign it the huffman code
        if( node.getValue() != 0 ) {
            nodeCodes encrypted = new nodeCodes();

            encrypted.setCode(code);
            encrypted.setValue(node.getValue());
            codes.add(encrypted);

        }

        // If this node has a left tree, iterate though the left side tree
        if( node.getLeft() != null )
            assignHuffmanCodeValues(node.getLeft(), code + "0");

        // If this node has a right tree, iterate though the right side tree
        if( node.getRight() != null )
            assignHuffmanCodeValues(node.getRight(), code + "1");

    }


    //method to sort linkedlist using selection sort
    public void sortList(LinkedList<HuffNode> hNodes){

        for (int i = 0 ; i!=hNodes.size();i++){

            for(int j = i+1; j!=hNodes.size();j++)

                if(hNodes.get(j).getWeight()<hNodes.get(i ).getWeight()){

                    HuffNode temp = hNodes.get(j);

                    hNodes.set(j, hNodes.get(i));
                    hNodes.set(i, temp);

                }

        }

    }

}

