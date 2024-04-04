package demos;
import demos.shapes.*;

public class Tester {
    public static void main(String[] args) {
        Point3D point1=new Point3D(),point2 = new Point3D();
        point1.x=0.0;
        point1.y=0.0;
        point1.z=0.0;
        point2.x=20.0;
        point2.y=20.0;
        point2.z=20.0;
        Box3D box1=new Box3D(point1,2,2,2);
        System.out.println("中心位置："+"("+box1.getCenter().x+","+box1.getCenter().y+","+box1.getCenter().z+")");
        System.out.println("体积："+box1.volume());
        System.out.println("表面积："+box1.surfaceArea());
        box1.setCenter(point2);
        System.out.println("中心位置："+"("+box1.getCenter().x+","+box1.getCenter().y+","+box1.getCenter().z+")");



    }
}
