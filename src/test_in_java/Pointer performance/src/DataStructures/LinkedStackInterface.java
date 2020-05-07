/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package DataStructures;

/**
 *
 * @author Indigo
 */
public interface LinkedStackInterface<T> {
    
    void push(T data);
    T pop();
    T peek();
    int size();
    void clear();
}
