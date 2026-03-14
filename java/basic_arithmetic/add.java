class Addition{
    public void add_int(int a, int b){
        System.out.println(a+b);
    }
    public void add_float(float a, float b){
        System.out.println(a+b);
    }
    public void add_double(double a, double b){
        System.out.println(a+b);
    }
}
class Main{
    public static void main(String[] args) {
        Addition add=new Addition();
        System.out.println("Sum of integers");
        add.add_int(2,3);
        add.add_int(-1, -2);
        System.out.println("Sum of float");
        add.add_float(0.1f, 1.0f);
        add.add_float(-0.1f, 1.0f);
        System.out.println("Sum of double");
        add.add_double(0.67676767, 0.67676767);
        add.add_double(-0.67676767, 0.67676767);

    }
}