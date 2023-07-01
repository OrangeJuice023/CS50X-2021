using System.Collections;
using System.Collections.Generic;
using UnityEngine;

// Initializes the file name of the script

public class AddPlayerControlledVelocity : MonoBehaviour
{
    // Uses the SerializeField attribute so that the variable will be modifiable in the unity editor.
    
    [SerializeField]
    Vector3 v3Force;

    // Uses the SerializeField attribute so that the variable will be modifiable will be modifiable in the unity editor.
    
    [SerializeField]
    KeyCode keyPositive;
    
    // Uses the SerializeField attribute so that the variable will be modifiable will be modifiable in the unity editor.
    
    [SerializeField]
    KeyCode keyNegative;

    /* Uses the FixedUpdate function in Unity so that the physics of the sprite or model that has
    this script will have a fixed physics system */
    
    void FixedUpdate ()
    {
        /* An if statement that produces an effect to the sprite or 3D elements when the
        keyPositive variable is used. */
        
        // Gets the input from the player   
        
        if (Input.GetKey(keyPositive))
        
            /* the vector force that is used by the keyPositive variable by combining it with 
            the ConstantVelocity Script */
            
            GetComponent<Rigidbody>().velocity += v3Force;
 
        /* the vector force that is used by the keyNegative variable by combining it with 
            the ConstantVelocity Script */
        
        // Gets the input from the player     
        
        if (Input.GetKey(keyNegative))
        
        /* the vector force that is used by the keyNegative variable by combining it with 
            the ConstantVelocity Script */
        
            GetComponent<Rigidbody>().velocity -= v3Force;
    }
}