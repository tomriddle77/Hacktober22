
 //Non perimeterized constructor

class student {

      String name = "Aarvi kashyap";
      int id = 34;

     student () {

         System.out.println("Initialising values: ");
         name = "Bull dog";
          id = 3;


     }

     }
 
// Default constructor

public class constructor_2 {
   constructor_2 () {
       System.out.println("Default constructor ");
   }
    public static void main(String[] args) {


       student s1 = new student();

        System.out.println("Name " + s1.name + " and his id is " + s1.id );

    }
}
