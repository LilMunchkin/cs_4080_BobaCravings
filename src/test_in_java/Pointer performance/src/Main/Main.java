/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Main;

import java.util.Random;
import DataStructures.LinkedStack;
import java.text.NumberFormat;
import java.util.Stack;
/**
 *
 * @author Indigo
 */
public class Main {
    

    public static void main(String[] args) 
    {
        int testType = 0; //switch this to change the test type. 0 = linked list stack, 1 = regular java array based stack
        
        final int NUM_ELEMENTS_TO_TEST = 1000000;
        
        //get info about memory usage
        Runtime runtime = Runtime.getRuntime();
        NumberFormat format = NumberFormat.getInstance();
        long maxMemory;
        long allocatedMemory;
        long freeMemory;
        
        //time recording variables
        long timeToInitialize;
        long timeToPush;
        long timeToPop;
        long totalTime; 
        long startTime;
        long timeToCheckMemory;
        
       switch (testType) {
            case 0 :
                //Testing speed of custom linked list stack
                startTime = System.currentTimeMillis();
                LinkedStack<Integer> linkedStack = new LinkedStack<>();
                timeToInitialize = System.currentTimeMillis() - startTime;

                for (int i = 0; i < NUM_ELEMENTS_TO_TEST; i++)
                {
                    linkedStack.push(i);
                }
                timeToPush = System.currentTimeMillis() - startTime - timeToInitialize;
                System.out.println("memory usage after pushing to stack: maxMemory=" + (runtime.maxMemory()/ 1048576) + " MB, allocatedMemory=" + (runtime.totalMemory()/ 1048576) + " MB, freeMemory=" + (runtime.freeMemory()/ 1048576) +" MB.");
                timeToCheckMemory= System.currentTimeMillis() - startTime - timeToInitialize - timeToPush;
                
                for (int i = 0; i < NUM_ELEMENTS_TO_TEST; i++)
                {
                    linkedStack.pop();
                }
                timeToPop = System.currentTimeMillis() - startTime - timeToPush - timeToInitialize - timeToCheckMemory;
                totalTime = timeToInitialize + timeToPush + timeToPop;
                

                System.out.println("\nExecution time for linked-list based stack: " + ((float)totalTime/1000f));
                System.out.println("Splits: Time to initialize=" + ((float)timeToInitialize/1000f) + ", time to push elements=" + ((float)timeToPush/1000f) + ", time to pop elements=" + ((float)timeToPop/1000f)+ ".");
                System.out.println("memory usage after popping:  maxMemory=" + (runtime.maxMemory()/ 1048576) + " MB, allocatedMemory=" + (runtime.totalMemory()/ 1048576) + " MB, freeMemory=" + (runtime.freeMemory()/ 1048576) +" MB.");
                break;
                
                case 1 :
                    
                    //Testing speed of custom array stack
                    startTime = System.currentTimeMillis();
                    Stack<Integer> stack = new Stack<>();
                    timeToInitialize = System.currentTimeMillis() - startTime;

                    for (int i = 0; i < NUM_ELEMENTS_TO_TEST; i++)
                    {
                        stack.push(i);
                    }
                    timeToPush = System.currentTimeMillis() - startTime - timeToInitialize;
                    System.out.println("memory usage after pushing to stack: maxMemory=" + (runtime.maxMemory()/ 1048576) + " MB, allocatedMemory=" + (runtime.totalMemory()/ 1048576) + " MB, freeMemory=" + (runtime.freeMemory()/ 1048576) +" MB.");
                    timeToCheckMemory= System.currentTimeMillis() - startTime - timeToInitialize - timeToPush;
                    
                    for (int i = 0; i < NUM_ELEMENTS_TO_TEST; i++)
                    {
                        stack.pop();
                    }
                    timeToPop = System.currentTimeMillis() - startTime - timeToPush - timeToInitialize - timeToCheckMemory;
                    totalTime = timeToInitialize + timeToPush + timeToPop;
                    System.out.println("\nExecution time for array stack: " + ((float)totalTime/1000f));
                    System.out.println("Splits: Time to initialize=" + ((float)timeToInitialize/1000f) + ", time to push elements=" + ((float)timeToPush/1000f) + ", time to pop elements=" + ((float)timeToPop/1000f)+ ".");
                    System.out.println("memory usage after popping: maxMemory=" + (runtime.maxMemory()/ 1048576) + " MB, allocatedMemory=" + (runtime.totalMemory()/ 1048576) + " MB, freeMemory=" + (runtime.freeMemory()/ 1048576) +" MB.");
                    break;
       }
    }
}
