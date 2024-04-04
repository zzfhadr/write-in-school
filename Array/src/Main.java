import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
       int a[] = {100,200,300};
       System.out.println(a.length);
       System.out.println(a);
       int b[][] = {{1},{1,1},{1,2,1},{1,3,3,1},{1,4,6,4,1}};
        System.out.println("数组B的长度："+b.length);
        System.out.println(b[4][2]);
        b[4]=a;
        System.out.println(b[4][2]);

        int c[]={1,2,3,4,500,600,700,800};
        int[] d,e,f;
        System.out.println("C:"+Arrays.toString(c));
        d=Arrays.copyOf(c,c.length);
        System.out.println("D:"+Arrays.toString(d));
        e=Arrays.copyOf(c,4);
        System.out.println("E:"+Arrays.toString(e));
        f=Arrays.copyOfRange(c,c.length-4,c.length);
        System.out.println("F:"+Arrays.toString(f));

        e[e.length-1]=-100;
        f[f.length-1]=-200;
        System.out.println(Arrays.toString(c));
        System.out.println(Arrays.toString(e));
        System.out.println(Arrays.toString(f));

    }
}