package demos.shapes;

public class Shape3D {
    private double width,height,depth;
    private Point3D center;

    public  Shape3D(Point3D c,double w,double h,double d)
    {
        this.depth=d;
        this.height=h;
        this.width=w;
        this.center=c;
    }
  public   double  getWidth()
    {
        return width;
    }
    public  double  getHeight()
    {
        return height;
    }
    public double  getDepth()
    {
        return  depth;
    }
    public  Point3D getCenter()
    {
        return center;
    }
    public  void setCenter(Point3D c)
    {
        center=c;
    }

}
