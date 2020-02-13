package secondassign.firstnumber;

import java.util.Scanner;

class Employee extends Member{
	
	
	String department = "";
	Employee()
	{
		System.out.println("Input name of employee: ");
		this.name = input.next();
		System.out.println("Input age: ");
		this.age = input.nextInt();
		System.out.println("Input phone number: ");
		this.phoneNumber = input.next();
		System.out.println("Input address: ");
		input.nextLine();
		this.address = input.nextLine();
		System.out.println("Input salary: ");
		this.salary = input.nextDouble();
		System.out.println();
		position = "Employee";
	}
	
}

class Manager extends Member{

	String specialization= "";
	String department = "";
	Manager()
	{
		
		System.out.println("Input name of manager: ");
		this.name = input.next();
		System.out.println("Input age: ");
		this.age = input.nextInt();
		System.out.println("Input phone number: ");
		this.phoneNumber = input.next();
		System.out.println("Input address: ");
		input.nextLine();
		this.address = input.nextLine();
		System.out.println("Input salary: ");
		this.salary = input.nextDouble();
		position = "Manager";
	}
}

public class Member {
	
	public static Scanner input = new Scanner(System.in);
	String position;
	String name;
	int age;
	String phoneNumber;
	String address;
	double salary;
	
	
	public void printSalary()
	{
		System.out.println("---------------------------");
		System.out.println("Name: " + this.name);
		System.out.println("Position: " + this.position);
		System.out.println("Age: "+ this.age);
		System.out.println("Phone Number: " + this.phoneNumber);
		System.out.println("Address: " + this.address);
		System.out.println("Current Salary: P " + this.salary);
		System.out.println("---------------------------");
	}
	

	public static void main(String[] args) {
			Employee empObject = new Employee();
			Manager manObject = new Manager();
			empObject.printSalary();
			manObject.printSalary();

	}

}
