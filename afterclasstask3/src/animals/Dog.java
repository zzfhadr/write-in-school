package animals;

public class Dog implements Animal{
    public void cry()
    {
        System.out.println("woof, woof, woof");
    }
    public String getAnimalName()
    {
        return   new String("Dog");
    }
}
