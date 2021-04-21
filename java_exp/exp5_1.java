public class exp5_1{
    public static void main (String[] args){
        Animal a = new Dog();
        a.cry();
        a = new Cat();
    a.cry(); 
    }
}
class Animal{
    void cry(){}
}
class Dog extends Animal{
    void cry(){
        System.out.println("woof wooof");
    }
}
class Cat extends Animal{
    void cry(){
        System.out.println('m');
    }
}