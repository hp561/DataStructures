public class nodeCodes {

    private char value;
    private String code;

    public nodeCodes(char value, String code){

        this.value=value;
        this.code=code;

    }

    public nodeCodes() {

    }


    public void setCode(String code){

        this.code=code;

    }


    public String getCode(){

        return code;
    }

    public void setValue(char val){

        this.value=val;

    }

    public int getValue(){

        return value;
    }
}
