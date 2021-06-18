public class CatchMoreExceptionExample {
    public static void main(String[] args) {
        // 受监视的代码
        try {
            // 创建数组对象
            int[] a = new int[4];
            // 超范围访问数组元素
            a[4] = 9;
        }
        // 异常处理代码
        catch (Exception e) {
            System.out.println("异常种类及消息为：" + e.toString() + "。");
        }
    }
}
