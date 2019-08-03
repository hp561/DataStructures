public class Node {


    private int row;
    private int col;
    private int data;

    public Node(int row, int col, int data){

        this.row=row;
        this.col=col;
        this.data=data;


    }

    public void setRow(int row){

        this.row=row;

    }

    public void setCol(int col){

        this.col=col;

    }
    public void setData(int data){

        this.data=data;

    }
    public int getRow(){

        return row;

    }

    public int getCol(){

        return col;

    }
    public int getData(){

        return data;

    }



}


