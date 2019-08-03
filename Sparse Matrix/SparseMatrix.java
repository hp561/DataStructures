import java.util.LinkedList;

public class SparseMatrix implements SparseInterface {

//size of matrix
    private int size;


    LinkedList <Node> matrix = new LinkedList<>();

    //constructor for matrix
    public SparseMatrix(){

        this.size=5;

    }

    //constructor for specific size
    public SparseMatrix(int size){

        this.size=size;

    }


    @Override


    public void clear() {

        matrix.clear();

    }

    @Override
    public void setSize(int size) {

        clear();
        this.size=size;

    }

    @Override
    public void addElement(int row, int col, int data) {


//this is to remove whatever is at the coordinate to avoid duplicates. if nothing is there it doesnt matter
        removeElement(row,col);

        //checking for invalid coordinates
        if(row>size || col>size || row<0 || col<0) {

            System.out.println("Invalid entry point");
            return;

        }
        if (data==0) {
            System.out.println("Can't  add zeros");
            return;
        }



//creates new node and adds it to LinkedList "matrix"
        Node newElement = new Node(row, col, data);
        matrix.add(newElement);

    }

    @Override
    public void removeElement(int row, int col) {

//checks for validation
        if(row>size || col>size || row<0 || col<0) {

            System.out.println("Invalid entry point");
            return;

        }

        //traverses through the nodes to find where col and row are same. once they are same remove that node from linked lost
       for (int i = 0; i<matrix.size();i++){

            Node nodes = matrix.get(i);

            if(nodes.getCol()==col&&nodes.getRow()==row){

                matrix.remove(i);
                break;

            }

       }



    }

    @Override

    //traverses through the nodes to find where col and row are same. once they are same get that node from linked lost
    public int getElement(int row, int col) {

        if(row>size || col>size || row<0 || col<0) {

            System.out.println("Invalid entry point");
            return -1;

        }
        int element=0;
        for (int i = 0; i<matrix.size();i++){

            Node nodes = matrix.get(i);

            if(nodes.getCol()==col&&nodes.getRow()==row){

                element=nodes.getData();


            }

        }

        return element;
    }

    @Override

    //used the the given equation to calculate determinate
    public int determinant() {

        if(this.size==1)
            return getElement(0,0);
        else {
            int det = 0;
            for (int i = 0; i < this.size; i++){
                det += Math.pow(-1, i) * getElement(0, i) * minor(0, i).determinant();
            }
            return det;


        }



    }

    @Override



    //traverses through the linkedlist. if the current nodes row and col are in the 1st quadrant of the split then new row stays same and col=col-1
    //traverses through the linkedlist. if the current nodes row and col are in the 2nd quadrant of the split then new row stays same and col
    //traverses through the linkedlist. if the current nodes row and col are in the 3rd quadrant of the split then new row=row-1  and col stays same
    //traverses through the linkedlist. if the current nodes row and col are in the 4th quadrant of the split then new row=row-1  and col=col-1
    public SparseInterface minor(int row, int col) {

        SparseMatrix newMatrix = new SparseMatrix(size-1);



        for (int i = 0; i<matrix.size();i++){

            Node nodes = matrix.get(i);

            if(nodes.getRow()<row && nodes.getCol()<col)
                newMatrix.addElement(nodes.getRow(), nodes.getCol(), nodes.getData());

            if(nodes.getRow()<row && nodes.getCol()>col)
                newMatrix.addElement(nodes.getRow(), nodes.getCol()-1 , nodes.getData());

            if(nodes.getRow()>row && nodes.getCol()<col)
                newMatrix.addElement(nodes.getRow()-1, nodes.getCol() , nodes.getData());

            if(nodes.getRow()>row && nodes.getCol()>col)
                newMatrix.addElement(nodes.getRow()-1, nodes.getCol()-1 , nodes.getData());

        }


        return newMatrix;





    }

    @Override

    //first for loop is to search rows in order, second for cols, and the third goes through linked list of nodes to see if they match
    public String toString() {

        String print = "";
        for(int i=0; i<size; i++){
            for(int j = 0; j<size; j++ ) {
                  for (int k = 0; k < matrix.size(); k++) {
                     Node e = matrix.get(k);
                     if (e.getRow() == i && e.getCol() == j) {
                         print += i + " " + j + " " + e.getData() + "\n";
        }
    }
}

}

        return print;


    }

    @Override
    public int getSize() {
        return this.size;
    }
}
