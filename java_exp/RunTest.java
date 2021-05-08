public class RunTest {
    public static void main(String[] args) {
        Runable r;
        r = new Cat();
        r.run();
        System.out.println("--------");
        r = new Dog();
        r.run();
    }
}

interface Runable {
    void run();
}

class Cat implements Runable {
    public void run() {
        System.out.println("cat");
    }
}

class Dog implements Runable {
    public void run() {
        System.out.println("dog");
    }
}