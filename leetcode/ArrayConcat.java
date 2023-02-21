public class ArrayConcat {

    public static int[] getConcatenation(int[] nums) {
        int[] concat = new int[nums.length * 2];
        for (int i = 0; i < nums.length; i++) {
            concat[i] = nums[i];
        }
        for (int i = 0; i < nums.length; i++) {
            concat[i + nums.length] = nums[i];
        }
        return concat;

    }

    public static void main(String[] args) {
        int[] c = getConcatenation(new int[]{1, 2, 3});
        for (int i = 0; i < c.length; i++) {
            if (i != c.length - 1) {
                System.out.print(c[i] + " ");
            } else {
                System.out.print(c[i]);
            }

        }
    }
}
