package animals;

public class Simulator {
    public void playSound(Animal animal)
    {

        System.out.println(animal.getAnimalName());
        animal.cry();
    }

}
