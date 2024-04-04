class A{
    public void fA(){
        System.out.println("I am A");
    }
}
class B{
    public void fB(){
        System.out.println("I am B");
    }
}
class C{
    public void fC(){
        System.out.println("I am C");
    }
}
public class Main{
    public static void main(String[] args) {
        A a = new A();
        a.fA();
        B b =new B();
        b.fB();
        C c = new C();
        c.fC();
    }
}