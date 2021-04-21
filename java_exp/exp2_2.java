import java.util.*;
public class exp2_2 {
   public static void lines(){
        for(int i = 0; i < 56;i++){
            System.out.print("-");  
       }
       System.out.println("");  
   }
   public static void stars(){
         for(int i = 0; i < 56;i++){
           if(i == 0 || i == 55){
               System.out.print("*");
           }else{
               System.out.print(" ");
           }
       }
       System.out.println("");
   }
   public static void enter(){
       System.out.println("Please make your choice:");
       System.out.println("1.Enter student's grade information;");
       System.out.println("2.Display student's grade information;");
       System.out.println("0.Exit;");
       System.out.print("Please enter the number(0-2):");
   } 
   public static void main(String[] args) {
       lines();
       stars();
       System.out.println("* Welcome to the management system of students' grade! *"); 
       stars();
       lines();
       enter();
       int flag = 1; 
       Scanner sc = new Scanner(System.in);
       while(flag == 1){
            switch( sc.nextInt()){
            case 0: flag = 0;break;
            case 1: flag = 0;break;
            case 2: flag = 0;break;
            default:  
                System.out.println("Input Error, please input again:");
                lines();
                stars();
                System.out.println("* Welcome to the management system of students' grade! *");
                stars();
                lines();
                enter();
                break;
        }
       }
   } 
}
