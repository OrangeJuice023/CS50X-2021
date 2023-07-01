// Importing Unity Engine libraries for scene loading

using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

// Initializes the file name of the script

public class RestartLevelOnCollision : MonoBehaviour
{
    // Inputs an editor field in Unity
    
    [SerializeField]
    
    // Targets what ever is in the strTag
    
    string strTag;

   // function the triggers the oncollision event
   
    private void OnCollisionEnter(Collision collision)
    {
        /* An if condition where if the object that has the on collision script collides with its 
        targeted tag, the condition will function. */
        
        if (collision.collider.tag == strTag)
            
            // The scene will load all over again if the if statement is true.
            
            SceneManager.LoadScene(SceneManager.GetActiveScene().name);
    }
}