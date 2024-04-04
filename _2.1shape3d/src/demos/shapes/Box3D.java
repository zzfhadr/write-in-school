package demos.shapes;

public class Box3D extends Shape3D {

    public Box3D (Point3D c,double w,double h,double d)
    {
        super(c,w,h,d);
    }
    public double volume()
    {

        double w,h,d;
        w=getWidth();
        h=getHeight();
        d=getDepth();
        return w*h*d;
    }
    public double surfaceArea()
    {

        double w,h;
        w=getWidth();
        h=getHeight();
        return 6*w*h;
    }

}
