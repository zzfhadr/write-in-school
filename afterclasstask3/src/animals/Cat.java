package animals;

public class Cat implements Animal{
    public void cry()
    {
        System.out.println("meow!meow!meow!");
    }
    public String getAnimalName()
    {
        String named = new String("Cat");
        return  named;
    }
}
