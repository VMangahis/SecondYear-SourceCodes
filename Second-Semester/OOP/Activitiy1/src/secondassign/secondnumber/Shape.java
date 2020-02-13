package secondassign.secondnumber;

class Square extends Rectangle{
	
	Square()
	{
		super.printForm();
	}
	
	public void printForm()
	{
		System.out.println("Square is a rectangle");
	}
	
}



class Rectangle extends Shape{
	
	public void printForm()
	{
		System.out.println("This is rectangular shape");
		super.printForm();
	}
	
	
	
}

class Circle extends Shape{
	
	public void printForm()
	{
		System.out.println("This is circular shape");
	}
	
}

public class Shape {
	
	public void printForm()
	{
		System.out.println("This is This is Shape");
	}

	public static void main(String[] args) {
	
		Square squareObject = new Square();
		
	}

}
