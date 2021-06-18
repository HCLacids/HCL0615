public class CatchMoreExceptionExample2 {
    public static void main(String[] args) {
        // 受监视的代码
        try {
            // 声明数组类型的空引用
            int[] a = null;
            // 通过空引用访问数组元素
            a[4] = 9;
        }
        // NullPointerExceptio的异常处理代码
        catch (NullPointerException npe) {
            System.out.println("产生空引用异常：" + npe.toString());
        }
        // Exception的异常处理代码
        catch (Exception e) {
            System.out.println("产生异常：" + e.toString());
        }
    }
}
