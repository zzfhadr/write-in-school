public class Tester {
    public static void main(String[] args) {
        SimCard c1=new SimCard("12345678901");
        SimCard c2=new SimCard("12345678902");
        Battery bt1=new Battery(2000);
        Battery bt2=new Battery(3000);
        CellPhone cellPhone= new CellPhone(c1,c2,bt1);
        System.out.println("卡1："+cellPhone.getCard1Number()+"，卡2："+cellPhone.getCard2Number()+"电池容量："+cellPhone.getBatteryCapacity());
        cellPhone.setBattery(bt2);
        System.out.println("新的电池容量："+cellPhone.getBatteryCapacity());
    }
}