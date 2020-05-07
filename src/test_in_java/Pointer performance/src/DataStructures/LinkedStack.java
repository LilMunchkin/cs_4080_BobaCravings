/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package DataStructures;

/**
 *
 * @author Indigo
 * a singly linked list for creating a stack.
 * @param <T> 
 */
public class LinkedStack <T> implements LinkedStackInterface<T> {
    private int size;
    private Node head;
    public LinkedStack(){
        size = 0;
        head = null;
    }
    @Override
    public void push(T data) {
        Node<T> node = new Node(data, head); 
        head = node;
        size++;
    }
    @Override
    public T pop() {
        if (size != 0) {
            T returnData = (T) head.data;
            head = head.next;
            size--;
            return returnData;
        }
        else{
            return null;
        }
    }
    @Override
    public T peek(){
        if (size != 0) {
            return (T) head.data;
        }
        else{
            return null;
        }
    }
    @Override
    public int size(){
        return size;
    }
    @Override
    public void clear(){
        head = null;
        size = 0;
    }
    
    public class Node<T> {
        Node next; //the next node in the linked list
        T data;
        Node (T data){
            this(data,null);
        }
        Node(T data, Node next) {
            this.data = data;
            this.next = next;
        }
    }
    
}
