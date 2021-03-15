
public class Potenza {
	static Integer base;
	
	private static Integer pot(Integer exp) {
		if (exp == 0)
			return 1;
		else
			return pot(exp-1) * 2;
	}
	
	public static void main(String[] args) {
		base = 2;
		for (Integer i=0; i<10; i++)
			System.out.println(pot(i));
	}
}
