import java.util.LinkedList;


public class HuffTree  {

    private LinkedList <HuffNode> huffTree = new LinkedList<HuffNode>();

    HuffTree(LinkedList<HuffNode> huffTree){

        this.huffTree=huffTree;

    }


    public LinkedList<HuffNode> getHuffTree(){


        return this.huffTree;
    }

    HuffTree(){


    }


    }

