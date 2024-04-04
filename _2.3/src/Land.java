
public class Land {
    public static void main(String[] args) {
        Village case1=new Village("赵庄",80);
        Village case2=new Village("马家河子",120);
        Village.waterAmount=200;
        System.out.println(case1.getName()+"村"+"，人数："+case1.getPeopeleNumber());
        System.out.println(case2.getName()+"村"+"，人数："+case2.getPeopeleNumber());
        case1.drinkWater(50);
        case2.drinkWater(100);
        System.out.println("剩余水量"+case1.getWaterAmount());



    }
}
