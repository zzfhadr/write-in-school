import java.lang.Math;
import java.net.ConnectException;
import java.util.Random;
import java.util.Scanner;
public class Main {
    public static int randInt(int min, int max) {

        // NOTE: Usually this should be a field rather than a method
        // variable so that it is not re-seeded every call.
        Random rand = new Random();

        // nextInt is normally exclusive of the top value,
        // so add 1 to make it inclusive
        int randomNum = rand.nextInt((max - min) + 1) + min;

        return randomNum;
    }

    public static void main(String[] args)
    {
        int wup;
        int wrower=0;
        int onthree=0;
        wup=12 + (int)(Math.random()*(20 - 12 +1));

        System.out.println("游戏初始化"+wup+"件物品");
        while (wup!=0&&wup>0)
        {
            Scanner myObj = new Scanner(System.in);
             wrower = myObj.nextInt();
            wup=wup-wrower;
            System.out.println("您减去"+wrower+"件物品"+"，物品剩余"+wup);
             onthree = randInt(1,3);
             if(wup<=3)
                 onthree=wup;
            wup=wup-onthree;
            System.out.println("计算机减去"+onthree+"件物品"+"，物品剩余"+wup);
        }
        if((wup+ onthree)==0)
            System.out.println("您赢得了本次游戏。");
        else if(wup==0)
            System.out.println("计算机赢得了本次游戏。");
    }
}