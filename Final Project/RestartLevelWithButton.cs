// Importing Unity Engine libraries for scene loading

using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

// Initializes the file name of the script

public class RestartLevelWithButton : MonoBehaviour
{
    // Inputs an editor field in Unity
    
    [SerializeField]
    KeyCode keyRestart;
	
	// Updates the game frame once
	void Update ()
    {
        //Gets player input
        
        if (Input.GetKey(keyRestart))
        
            // Loads the active scene
            SceneManager.LoadScene(SceneManager.GetActiveScene().name);
	}
}
