// Importing Unity Engine libraries for scene loading

using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

// Initializes the file name of the script

public class Portal : MonoBehaviour
{

    //public string LevelName;
    public int LevelIndex;

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    
    void OnTriggerEnter(Collider other)
    {
        /* If the game object that it targets has a "Player" tag, 
        then it will load the level or scene that it indexes to next. */
        
        if(other.gameObject.tag == "Player")
        SceneManager.LoadScene(LevelIndex);
    }
}