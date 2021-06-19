public class Bank_Syn {
    public static void main(String[] args) {
        Customer c1 = new Customer(); // 创建Customer对象 c1
        Customer c2 = new Customer(); // 创建Customer对象 c2
        c1.start(); // 启动c1开始取现
        c2.start(); // 启动c2开始取现
    }
}

class Mbank {
    int sum = 2000; // 定义一个私有静态整型变量sum表示账户初始现金，并设置为2000

    public void take(int k) // 定义一个公共同步静态无返回值的取现方法take(int k)，k为取现金额
    {
        int temp = sum;
        temp -= k;
        try {
            Thread.sleep((int) (1000 * Math.random()));
        } catch (InterruptedException e) {
        }
        sum = temp;
        System.out.println("sum=" + sum);
    }
}

class Customer extends Thread {
    Mbank bank = new Mbank();

    public void run() // 定义公共无返回值的run()方法
    {
        for (int i = 1; i <= 4; i++) {
            bank.take(100); // 调用Mbank类的take方法取现100元
        }
    }
}
