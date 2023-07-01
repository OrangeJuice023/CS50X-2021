# BallStacle
BallStacle is simple 3D obstacle game that is made using the Unity Game Engine. Each of the elements that interact with the player
uses a code component that is written in the programming language of C#. C# is frequently utilized in the Unity game engine, which 
is now the most popular game engine. Unity is used to produce more than a third of the top games, and the Unity engine has around 770 million active users.

### Game Video Demo:  <https://youtu.be/CxqYS40uGDE>
This is a gameplay for the game that I made. As you can see, it uses very simple mechanics that is very much like a normal obstacle game that you can
play. The challenge here though is, to pass through all of the obstacles and reaching the end of the level without failing. 

Hope you will have fun and enjoy!

### Game Video Demo:  <https://play.unity.com/mg/other/final-na-mapeh>
This is the game itself that you can play on the Unity's Community Website. GLHF and Stay Frosty!

# Building the Game:
Let's first discuss the codes that I made to be used as a component for the elements in-game so that the game will be dynamic.

## The Codes Behind:

### MainMenu.cs
This script in as event trigger that makes any sprite in your game acts as trigger to change your current scene.

Code: 
```
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

```

<img  alt="Main Menu" src="/project/images/Main-Menu.png">
As you can see in the in the image specifically on the lower right part, the Main Menu buttons uses the MainMenu.cs script so 
that the buttons would function as they are intended to.

### AddConstantVelocity.cs
This script is the one resposible for enabling the sprites or 3D elements in Unity will be able to move at a certain speed or
using the vector force in Physics.

Code: 
```
// Importing Unity Engine libraries for scene loading

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
```

<img  alt="Constant Velocity" src="/project/images/AddConstantVelocity.png">
As you can see in the in the image specifically on the lower right part, the bridge element or the green platform used the 
AddConstantVelocity script as a component so that it is able to move in the game with its velocity and
the best is that the speed can be edited in the Unity editor itself.

### AddPlayerControlledVelocity.cs
This script is the one resposible for enabling the user to move the sprites or 3D elements in Unity when it is built. Combining it with the
AddConstantVelocityScript, the game maker can modify the buttons that the player can interact physically so that the elements in the game will move.

Code: 
```
// Importing Unity Engine libraries for scene loading

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
```

<img  alt="Player Controls" src="/project/images/AddPlayerControlled.png">
As you can see in the in the image specifically on the lower right part, the player 3D model (Cube) uses the 
AddPlayerControlledVelocity script so that uses player inputs such as the Up and Down arrow key so that the player model
can move correspondingly with the player. You can add a lot of these scripts to a single element for better dynamics.

### RestartLevelWithButton.cs
So this script is not really fundamental in-game but it is more of a safety feature for the player. So when the player wants
to restart the level, they can just press the corresponding key bind that uses the script.

Code: 
```
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

```

<img  alt="Player Controls" src="/project/images/RestartLevelWithButton.png">
As you can see on the image specifically on the right part, you can see that it is used by an element in the game as component that is
not visible because it doesn't really have function. It rather waits directly for the players input to change something and has a keybind 
of the letter R.

### CopyPosition.cs
So this script utilizes objects' position in the game so that the sprite or the 3D elements that uses this script will be able to copy
the position of its targeted object.

Code: 
```
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

```

<img  alt="Camera Rig" src="/project/images/CopyPosition.png">
As you can see on the image, it is used by an element called camera rig that also contains the main camera. It is used by it so that the 
main camera can copy the targeted object's position e.g Player, so that the camera will be stable as the player moves through out the map.

### RestartLevelOnCollision.cs
So this script utilizes an object that can be used as a trigger for the game to restart. When the object that uses it collides with its targeted
object, the scene will load all over again.

Code: 
```
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

```

<img  alt="On Collision" src="/project/images/RestartLevelOnCollisionScript.png">
As you can see on the image specifically on the lower right part, this script is utilized by the base or platform of the whole map, what this does 
to the platform is that is it targets an element that is named "Player", once that player touches the platform, the scene will load over again therefore 
having produced the restart effect.

### Bridge.cs
This script is used by elements in the game that acts as an automatic platform e.g Bridge, to make the game a lot more automatic and dynamic. It can
be used by a lot of elements but you'll need to set it up so that it could act as a trigger.

Code: 
```
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

```

<img  alt="Bridge Trigger" src="/project/images/Bridge.png">
As you can see on the image, this is used by a sprite or 3D model that is not visible in the map. This is because
it acts as a trigger to that the objects that contains the sprite or 3D model that uses script is affected by the trigger. You'll need 
to set it up in a way that the object that uses the script is a parent object meaning it contains objects under it.

### Portal.cs
This script is used by elements or objects that acts as a finish line for a level such that the level changes or progresses. This uses a collider component
so that means that once an element that is tagged by the object that uses this script, the script will function.

Code: 
```
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

```

<img  alt="Finish Line" src="/project/images/Portal.png">
As you can see on the image, this is used by a sprite or 3D model that acrs as a finish line in the game. When the player touches this object or element, 
that level or scene will change as the function indexes to its reference level index. It is recommended to use this script only to objects that will act as 
the finish line for the game on every level.

## Materials That Makes Up The Game:

### Animations

<img  alt="Animations" src="/project/images/Animations.png">
As you can see on the image, there are these animations in Unity that is utilized by some of the elements in my game specifically the bridge element (blue)
and the elevator (green). These animations make most of the automatic movements in-game look very smooth.

### Background Images

<img  alt="Background Images" src="/project/images/BG.png">
As you can see on the image, I utilized some images to act as a background image for my main menu and exit menu. I used 3D synthwave type of image
because it looks cool and aesthetic and also gives off that gamer vibes.

### Materials

<img  alt="Materials" src="/project/images/Materials.png">
As you can see on the image, I utilized some materials for my game so that I can use a lot of colors to make my game pleasing and aesthetic to the player.
I specifically put red, blue, and yellow colors to the platform bases because I want to represent the Philippines.

### Post Processing

<img  alt="Materials" src="/project/images/PostProcessing.png">
As you can see on the image, I utilized some post processing materials for my Unity, some of which included scripts in order to help my game look better
and work.

### Scenes

<img  alt="Materials" src="/project/images/Scenes.png">
As you can see on the image, I made 5 scenes to make my game a simple yet complete one that has 3 levels. It has a Main Menu, Level 1-3, and an Exit Menu.

### Scripts

<img  alt="Materials" src="/project/images/Scripts.png">
As you can see on the image, I utilized a lot of C# Scripts in order for every element or objects in my game to function. Using the programming language
of C# is really easy and simple especially in programming games.

### Music

<img  alt="Materials" src="/project/images/Music.png">
As you can see on the image, I utilized a lot of music so that my game will not feel quiet and it will give the different dimensions that a gamer must feel
in order to be immersed in the game itself. I utilized 8-bits because they are the ones used in games that are simple and oldies. 

### Fonts 

<img  alt="Materials" src="/project/images/LiberationSans.png">
As you can see on the image, I utilized a Liberation Sans Font for my Main Menu and Exit Menu buttons. It is a well-known text and it is neutral.

# My Final Message:
Hello World! This course really helped to become a more knowledgeable person in the world of coding. At first, I entered this course to take heed of
the different programming languages that makes up most of our technology that we use today. But the best thing that this course taught is that, these programming 
languages are actually not the things that a person should really focus their attention in trying to learn programming but rather, the ways on how to become a better
programmer. A lot of concepts taught by this course really gave me a foundation now on how codes and programms work and how can they be improved in order to make 
a better version of itself. The last lesson that I would like to share that I learned in this course is that in life, things will always have a trade-off, and you
are the one who is responsible for picking which is a better option. As a 17-year old kid, I thank you Harvard and the CS50 teaching staff for all of the learnings.
THANK YOU!

# THIS IS CS50!
