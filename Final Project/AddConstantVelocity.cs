using System.Collections;
using System.Collections.Generic;
using UnityEngine;

// Initializes the file name of the script

public class AddConstantVelocity : MonoBehaviour
{
    // Uses the SerializeField attribute so that the variable will be modifiable.
    
    [SerializeField]
    
    /* The Vector3 variables is changed so that it will depend on the name of the sprite or model and
    it will be avaible in the unity editor itself to be edited */
    
    Vector3 v3Force;

    /* Uses the FixedUpdate function in Unity so that the physics of the sprite or model that has
    this script will have a fixed physics system */
    
	void FixedUpdate ()
    {
        /* Interacts with the rigid body component so that the sprite or model will move
        by interacting with its velocity vector */
        
        GetComponent<Rigidbody>().velocity += v3Force;
	}
}
