// Importing Unity Engine libraries for scene loading

using System.Collections;
using System.Collections.Generic;
using UnityEngine;
// library for managing scenes in Unity
using UnityEngine.SceneManagement;

// Initializes the file name of the script 

public class MainMenu : MonoBehaviour
{
   //A public function so that it acts as a call back in the main menu buttons
   
   public void PlayGame ()
   {
       /* Simply loads the next scene so that the play button can act properly using the scene manager function
       by getting the current scene's build index and adds 1 onto it to change the level or scene.*/
       
       // the build index can be found in the build settings
       
      SceneManager.LoadScene(SceneManager.GetActiveScene().buildIndex + 1);
   }

   // A public function that closes the game or the program
   
   public void QuitGame ()
   {
       /* Used Debug.log since this won't happen inside of the unity Editor
       and just to make sure that it will work */
       
       Debug.Log ("QUIT");
      Application.Quit();
   }
}
