// Importing Unity Engine libraries for scene loading

using System.Collections;
using System.Collections.Generic;
using UnityEngine;

// Initializes the file name of the script

public class Bridge : MonoBehaviour
{
    // Gets the animator component of the sprite or 3D model
    
    Animator animator;

    void Start()
    {
        // Gets the animtor component at the start of the event of the child elements or object
        
        animator = GetComponentInChildren<Animator>();
    }
    
        // Function that is used by objects that functions as a trigger to an animation

    private void OnTriggerEnter(Collider collider)
    {
        // If the object that uses the script collides with a tag named "Player" it will trigger an animation
        
        if (collider.tag == "Player")
        {
            // The animation triggered by the collider
            
            animator.SetTrigger("Lower Bridge");
        }
    }
}