/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package punishment;

/**
 *
 * @author Meticulous
 */
public class Punishment {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        int n_times = 0;
        
//        while(n_times<1000)
//        {System.out.println("I will always come to class");
//        n_times++;
//        }
        
        do {        
            n_times++;
            System.out.println(n_times);
            
        } while (n_times<1000);
        
    }
    
}
