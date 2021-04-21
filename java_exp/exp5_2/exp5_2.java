package exp5_2;
public class exp5_2{
    public static void main(String[] args){
        Animal a;
        a = new Cat();
        a.cry();
        a.eat();
        a = new Dog();
        a.cry();
        a.eat();
    }
}