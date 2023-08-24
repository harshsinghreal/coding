import java.util.Arrays;

public class Main {
	public static void main(String[] args) {
		int a = 5, b = 10, c = 3;
		
		int min_value = Arrays.stream(new int[] {a, b, c}).min().getAsInt();
       // int min_value =  oneDay>twoDay ? (twoDay>threeDay ? threeDay : twoDay) : (oneDay>threeDay ? threeDay : oneDay);
 
		
		System.out.println("The smallest value is " + min_value);
	}
}
