public class HuffNode {

    private char value;
    private HuffNode left;
    private HuffNode right;
    private int weight;

    public HuffNode(char value, HuffNode left, HuffNode right, int weight){

        this.value=value;
        this.right=right;
        this.left=left;
        this.weight=weight;

    }

    public char getValue (){

        return value;
    }

    public int getWeight(){

        return weight;
    }

     public void setValue(char newVal){

        this.value=newVal;
    }

    public void setWeight(int newWeight){

        this.weight = newWeight;
    }


    public void setLeft(HuffNode leftChild){

        this.left = leftChild;

    };

    public void setRight(HuffNode rightChild){

        this.right = rightChild;

    };

    public HuffNode getLeft(){

        return left;
    }

    public HuffNode getRight() {
        return right;
    }
}
