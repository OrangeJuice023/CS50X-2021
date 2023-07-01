// Importing Unity Engine libraries for scene loading

using System.Collections;
using System.Collections.Generic;
using UnityEngine;

// Initializes the file name of the script

public class CopyPosition : MonoBehaviour
{
     // Inputs an editor field in Unity
     
    [SerializeField]
    Transform transTarget;

    // Updates the game frame once
    
	void Update ()
    {
        // Copies the targeted position of the object
        
        transform.position = transTarget.position;
	}
}