
public class Vehicle {
String name;
float speed,mpg;
Vehicle(String Name,float Speed, float Mpg){
    name=Name;
    speed=Speed;
    mpg=Mpg;
}
public float tripCost(float distance,float gasCostPerGallon,float hotelCostPerNight){
    float cost;
    int nights;
    cost = (distance / mpg) * gasCostPerGallon;
    nights= (int)(distance/speed/8f);
    cost=cost+(float) nights*hotelCostPerNight;
    return  cost;
}
}
class  Tester {
    public static void main(String[] args) {
        Vehicle v1,v2;
        v1= new Vehicle("Bugatti",100.0f,1.0f);
        v2= new Vehicle("Vespa",30.0f,100.f);
        System.out.println("1000.0 miles in vehicle "+"'"+v1.name+"'"+" will take "+(1000.0/v1.speed/8f)+" days ("+(int)(1000.0/v1.speed/8f)+" night) and cost $"+v1.tripCost(1000,2.10f,55.0f));
        System.out.println("1000.0 miles in vehicle "+"'"+v2.name+"'"+" will take "+(1000.0/v2.speed/8f)+" days ("+(int)(1000.0/v2.speed/8f)+" nights) and cost $"+v2.tripCost(1000,2.10f,55.0f));
        if(v2.tripCost(1000,2.10f,55.0f)>v1.tripCost(1000,2.10f,55.0f))
            System.out.println("To save money, use "+"'"+v1.name+"'");
        else
            System.out.println("To save money, use "+"'"+v2.name+"'");
    }
}