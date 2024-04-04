package test2;

import java.util.Scanner;

public class StringWithUtilities
{
    private String str;
    public StringWithUtilities(String str)
    {
        this.str=str;
    }
    public void setString()
    {
        Scanner reader = new Scanner(System.in);
        str=reader.nextLine();
    }
    public void getString()
    {
        System.out.println(str);
    }
    public char[]  getCharArray()
    {
        char array[];
        array=str.toCharArray();
        return array;
    }
    public void printVowelStats()
    {
        int a,e,i,o,u,NonVowls;
        a=e=i=o=u=0;
        NonVowls=str.length();
        for(char ch:str.toCharArray())
        {
            if(ch=='a'||ch=='A')
                a++;
            if(ch=='e'||ch=='E')
                e++;
            if(ch=='i'||ch=='I')
                i++;
            if(ch=='o'||ch=='O')
                o++;
            if(ch=='u'||ch=='U')
                u++;
        }
        NonVowls=NonVowls-a-e-i-o-u;
        System.out.println("'Octopus' has "+a+" 'a's, "+e+" 'e's, "+i+" 'i's, "+o+" 'o's, "+u+" 'u's, and "+NonVowls+" non-vowels.");
    }
    public void leastChar()
    {

        int index=0;
        int position=0;
        char temp='z';
        for(char ch:str.toCharArray())
        {
            if((int)ch>91)
                ch=(char)((int)ch-32);
            if((int)temp>=(int)ch)
            {
                temp=ch;
            }
            index++;
        }
        index=0;
        for(char ch:str.toCharArray())
        {
            if((int)ch>91)
                ch=(char)((int)ch-32);
            if(temp==ch)
            {
                position=index;
                break;
            }

            index++;
        }
        temp=str.charAt(position);
        System.out.println("The least char is '"+temp+"' and occurs at position "+position);
    }
    public void printStringStats()
    {
        int counter=0;
        int index=0;
        char paisu[]=new char[155];//afraid it's not enough
        for(char ch:str.toCharArray())
        {
            if((int)ch>91)
                ch=(char)((int)ch-32);
            paisu[index]=ch;
            index++;
        }

        char temp;
        do
        {
            counter=0;
            for(index=0;index<str.length()-1;index++)
            {


                    if(paisu[index]<paisu[index+1])
                    {
                        temp=paisu[index];
                        paisu[index]=paisu[index+1];
                        paisu[index+1]=temp;
                        counter++;
                        //System.out.println("reach here"+counter);

                    }

            }

/*            for(index=0;index<str.length();index++)
            {
                System.out.print(paisu[index]);
            }
            System.out.print("\n");*/
        }
        while (counter!=0);

        char gesuo[][]=new char[26][2];
        counter=1;
        int zimu=0;
        paisu[str.length()]='0';
        for(index=0;index<str.length();index++)
        {

            if(paisu[index]==paisu[index+1])
            {
                counter++;
            }
            else
            {
                gesuo[zimu][0]=paisu[index];
                gesuo[zimu][1]=(char)(counter+'0');
                counter=1;
                zimu++;
            }
        }
        int zuiduo=0;
        for(index=0;index<zimu;index++)
        {
            if(gesuo[zuiduo][1]<gesuo[index+1][1])
                zuiduo=index+1;
        }
        if(zimu>=2)
            System.out.println("In '"+str+"', the largest letter is '"+gesuo[0][0]+"', the third largest letter is '"+gesuo[2][0]+"', and the most common letter is '"+gesuo[zuiduo][0]+"', occuring "+gesuo[zuiduo][1]+" times");
        else
            System.out.println("In '"+str+"', the largest letter is '"+gesuo[0][0]+"', there is no third largest letter, and the most common letter is '"+gesuo[zuiduo][0]+"', occuring "+gesuo[zuiduo][1]+" times");

    }
    public void finalize()
    {
        System.out.println("Finalizing class with String:"+str);
    }

}
 class  Tester
 {
     public static void main(String[] args)
     {
         StringWithUtilities object=new StringWithUtilities("Aldnasdlfkaaaa");
         object.printVowelStats();
         object.leastChar();
         object.printStringStats();
         object.setString();
         char another[]=object.getCharArray();
         System.out.println(another);
     }
 }