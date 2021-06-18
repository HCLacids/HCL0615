public class TryCatchFinallyExample {
    public static void main(String[] args) {
        // 受监视的代码块
        try {
            // 创建长度为4的int型数组
            int[] a = null;
            System.out.println("整型数组创建完毕！！");
            // 为数组最后一个元素赋值
            a[4] = 9;
            System.out.println("整型数组中第四个元素的数值为" + a[3]);
        }
        // 处理下标越界异常
        catch (ArrayIndexOutOfBoundsException aiobe) {
            // 打印提示信息
            System.out.println("这里出现的错误类型是：数组下标越界！！");
        }
        // 处理空引用异常代码块
        catch (NullPointerException npe) {
            // 打印提示信息
            System.out.println("这里出现的错误类型是：空引用！！");
        }
        // finally块
        finally {
            // 打印提示信息
            System.out.println("这里是finally块，无论是否抛出异常，这里总能执行！");
        }
        System.out.println("主程序正常结束！！！");
    }
}
