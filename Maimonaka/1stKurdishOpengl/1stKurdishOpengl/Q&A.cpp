
/*
<Q1>
hi, I have the //****************************************************************************************** <model one>
		glm::mat4 model(1.0f);
		model = glm::mat4(1.0f); //modely Yakam Atomaka
		model = glm::translate(model, glm::vec3(0.0f, 3.0f, -2.5f));
		model = glm::scale(model, glm::vec3(0.01f, 0.01f, 0.01f));
		//model = glm::rotate(model, curAngle * toRadians,glm::vec3(0.0f, 1.0f, 0.0f));
		glm::vec3 ModelPositionyYakam = getModelPosition(model);
		//bool modelNumb = false; //using this bool to echo the ModelPositionyYakam once. :) am learning
			for (int i = 0;i< modelInt; i++)
			{
				if (i>5 && printModelPositionOnce)
				{
					std::cout << " ModelPositionyYakam:/n";
					std::cout << " x " << ModelPositionyYakam.x << " y " << ModelPositionyYakam.y << " z " << ModelPositionyYakam.z;
				}
			}

		if (direction)
		{
			triOffset += triIncrement;
		}
		else
		{
			triOffset -= triIncrement;
		}
		if (abs(triOffset) >= triMaxoffset) //abs means absolute
		{
			direction = !direction;  //its a switch
		}
		curAngle += 0.01f;
		if (curAngle >= 360)
		{
			curAngle -= 360;
		}
		if (sizeDirection) {
			curSize += 0.0001f;
		}
		else
		{
			curSize -= 0.0001f;
		}

		if (curSize >= maxSize || curSize <= minSize)
		{
			sizeDirection = !sizeDirection;
		}

		model = glm::scale(model, glm::vec3(0.01f, 0.01f, 0.01f));
		model = glm::translate(model, glm::vec3(-2.0f, -3.0f, -13.0f)); //model2 = glm::translate(model2, position2);
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		atomModel.RenderModel();  // rendery attomaka modely yakam

		//****************************************************************************************** </model one>



//****************************************************************************************** <model two>

	glm::mat4
		modelyMarix = glm::mat4(1.0f);// modely Dwham Marixaka
		modelyMarix = glm::translate(modelyMarix, glm::vec3(10.0f, 1.0f, 10.0f)); //model2 = glm::translate(model2, position2);
		modelyMarix = glm::scale(modelyMarix, glm::vec3(0.1f, 0.1f, 0.1f));
		modelyMarix = glm::rotate(modelyMarix, curAngle * toRadians,
			glm::vec3(0.0f, 1.0f, 0.0f));

		glm::vec3 ModelPositionyDwam = getModelPosition(modelyMarix);

		for (int i = 0; i < modelInt; i++)
		{

			if (i > 5 && printModelPositionOnce)
			{
				std::cout << " ModelPositionyDwam:/n";

				std::cout << " x " << ModelPositionyDwam.x << " y " << ModelPositionyDwam.y << " z " << ModelPositionyDwam.z;
				//printModelPositionOnce = false; la ModelPositionySeham bika ba false boy harseloopy printing position complete kat
			}
		}
		if (gawra)
		{
			modelyMarix = glm::rotate(modelyMarix, curAngle * 1, glm::vec3(0.0f, 0.01f, 0.0f));
		//model = glm::scale(model, glm::vec3(0.3f, 0.3f, 0.3f));
			modelyMarix = glm::translate(modelyMarix, glm::vec3(0.0f, -12.0f, 0.0f));

		}
		Mars.useTexture();  // wata Amjora Texture'a bakar bena bo Am modela.
		//brick.useTexture(); // wata Amjora Texture'a bakar bena bo Am modela.
		shinyMaterial.UseSht(uniformSpecularIntensity, uniformShininess);


		if (sarawa)
		{
			modelyMarix = glm::rotate(modelyMarix, curAngle, glm::vec3(1.0f, -10.0f, 0.0f));
			modelyMarix = glm::translate(modelyMarix, glm::vec3(0.0f, -1.0f, 10.0f));
		}
		else
		{
			modelyMarix = glm::rotate(modelyMarix, curAngle, glm::vec3(1.0f, -1.0f, 0.0f));
			modelyMarix = glm::translate(modelyMarix, glm::vec3(0.0f, -1.0f, 0.0f));
		}
		//camera.Update();
		// Calculate the direction vector from the center of rotation to the camera position


		glm::mat4 viewMatrix = camera.calculateViewMatrix();
		if (swranawa)
		{
			//glm::vec3 direction = camera.position - camera.centerOfRotation;

			//// Rotate the direction vector using glm::rotate
			//direction = glm::rotate(glm::mat4(1.0f), glm::radians(1.0f), camera.front) * glm::vec4(direction, 0.1f);

			//// Update the camera position by adding the rotated direction vector to the center of rotation
			//camera.position = camera.centerOfRotation + direction;
			//
			glm::vec3 direction = camera.position - camera.centerOfRotation;

			// Define the rotation angle (in radians) for rotating around the equator.
			// You can adjust this angle to control the speed and direction of rotation.
			float rotationAngle = glm::radians(0.1f); // less radians slower it moves, I think.

			// Calculate the new position by rotating the direction vector around the up vector (vertical axis).
			direction = glm::rotate(glm::mat4(1.0f), rotationAngle, camera.up) * glm::vec4(direction, 0.1f);

			// Update the camera position while keeping the center of rotation unchanged.
			camera.position = camera.centerOfRotation + direction;


		}
		else
		{


		}

		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(modelyMarix));

		MeshList[2]->RenderMesh(); //rendery marixaka modely dwam
		shinyMaterial.UseSht(uniformSpecularIntensity, uniformShininess);


		//****************************************************************************************** </model two> //these two models 'model' and 'modelyMarix ' and I want to make them collision checked using this   bool CheckCollision(GameObject &one, GameObject &two) // AABB - AABB collision
{
	// collision x-axis?
	bool collisionX = one.Position.x + one.Size.x >= two.Position.x &&
		two.Position.x + two.Size.x >= one.Position.x;
	// collision y-axis?
	bool collisionY = one.Position.y + one.Size.y >= two.Position.y &&
		two.Position.y + two.Size.y >= one.Position.y;
	// collision only if on both axes
	return collisionX && collisionY;
}   how to make this happen
***************************************************************** </Q1>
//conclusion and worked and tested

//Class of detection collision
class GameObject
{
public:
	glm::vec3 Position;
	glm::vec3 Size;
	// Add other attributes if needed

	GameObject(glm::vec3 pos, glm::vec3 size) : Position(pos), Size(size) {}
};


	//****************************** for collision to be or not to be
bool CheckCollision(GameObject& one, GameObject& two)
{
	// Collision x-axis?
	bool collisionX = one.Position.x + one.Size.x >= two.Position.x &&
		two.Position.x + two.Size.x >= one.Position.x;
	// Collision y-axis?
	bool collisionY = one.Position.y + one.Size.y >= two.Position.y &&
		two.Position.y + two.Size.y >= one.Position.y;
	// Collision z-axis?
	bool collisionZ = one.Position.z + one.Size.z >= two.Position.z &&
		two.Position.z + two.Size.z >= one.Position.z;
	// Collision only if on all three axes
	return collisionX && collisionY && collisionZ;
}

	//****************************** end of for collision to be or not to be

//end of Class of detection collision

//after the model1
	glm::mat4 model(1.0f);
		model = glm::mat4(1.0f); //modely Yakam Atomaka
		model = glm::translate(model, glm::vec3(0.0f, 3.0f, -2.5f));
		model = glm::scale(model, glm::vec3(0.01f, 0.01f, 0.01f));
		....
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));
		//under this
//********************* <for collision model 1 'GameObject'>
		// Model 1
		glm::vec3 modelPosition = glm::vec3(0.0f, 3.0f, -2.5f);
		glm::vec3 modelSize = glm::vec3(0.01f, 0.01f, 0.01f);
		GameObject modelObj(modelPosition, modelSize);
		//********************* </for collision model 1>
	//same for model 2

		//********************* <for collision model 2 'GameObject'>
		// Model 2
		glm::vec3 modelyMarixPosition = glm::vec3(10.0f, 1.0f, 10.0f);
		glm::vec3 modelyMarixSize = glm::vec3(0.1f, 0.1f, 0.1f);
		GameObject modelyMarixObj(modelyMarixPosition, modelyMarixSize);
		//********************* </for collision model 2>
		// doesn't matter after or before .. glUniformMatrix4fv(uniformModel...
		//so its cool where you add it

		//.... after those two add this ...
			// Lets see if they 'those two models are' do collide
		if (CheckCollision(modelObj, modelyMarixObj))
		{
			std::cout << "Collision Detected!" << std::endl;
		}
		//

	//you can do it for other models too, for example:

		//********************* <for collision model 4 'GameObject'>
	// Model 4
		glm::vec3 modelMamaAkamPosition = glm::vec3(10.0f, 1.0f, 10.0f);
		glm::vec3 modelMamaAkamSize = glm::vec3(0.1f, 0.1f, 0.1f);
		GameObject modelMamaAkamObj(modelMamaAkamPosition, modelMamaAkamSize);
		//********************* </for collision model 4>

		 //alright, so lets see we want to get the position while the objects move
		//what then? ok go to Q2
// end of conclusion
***************************************************************** <Q2>

Q2/a/
 if I have the translate like glm::translate(modelMamaAkam, glm::vec3(-1.0f, 1.0f, 1.0f));  how to get the position while they 'models' move around in air

A/
  a/
 instead of

		glm::vec3 modelMamaAkamPosition = glm::vec3(10.0f, 1.0f, 10.0f);
		glm::vec3 modelMamaAkamSize = glm::vec3(0.1f, 0.1f, 0.1f);
		GameObject modelMamaAkamObj(modelMamaAkamPosition, modelMamaAkamSize);

		to get the position when they already moving
		you can do the following
Given that you have a transformation matrix like :

glm::mat4 modelMamaAkam = glm::mat4(1.0f);
modelMamaAkam = glm::translate(modelMamaAkam, glm::vec3(-1.0f, 1.0f, 1.0f));
To extract the translation(position) from the transformation matrix, you can use :

glm::vec3 position = glm::vec3(modelMamaAkam[3]);


Q2/b/
and for size? I have for example
modelMamaAkam = glm::scale(modelMamaAkam, glm::vec3(0.1f, 0.1f, 0.1f)); ?

A/b/
To extract the scale component from a transformation matrix, things get a little more involved than extracting translation. This is because scaling doesn't have its own dedicated section of the matrix like translation does. Instead, scaling affects the matrix's basis vectors (the first three columns).

Given the model matrix:
glm::mat4 modelMamaAkam = glm::mat4(1.0f);
modelMamaAkam = glm::scale(modelMamaAkam, glm::vec3(0.1f, 0.1f, 0.1f));
To extract the scale, you'd need to compute the lengths of these basis vectors:

glm::vec3 scale;
scale.x = glm::length(glm::vec3(modelMamaAkam[0]));  // Length of the first column (x-axis scaling)
scale.y = glm::length(glm::vec3(modelMamaAkam[1]));  // Length of the second column (y-axis scaling)
scale.z = glm::length(glm::vec3(modelMamaAkam[2]));  // Length of the third column (z-axis scaling)

Q2/c/
so, for example? can I use if (CheckCollision(position , scale))   instead of if(CheckCollision(modelObj, modelyMarixObj)) ?

A/c/
	The function you provided earlier for collision checking, CheckCollision(GameObject &one, GameObject &two), is designed for AABB (Axis-Aligned Bounding Box) collision detection between two GameObject objects. The function specifically checks for collisions based on the Position and Size properties of the GameObject.

If you want to check for collisions using the position and scale you extracted from the transformation matrix, you'd need to slightly modify the function or adapt the way you call it.

Here's how you can adapt it:

Define a simple struct for the purpose:

struct Object {
	glm::vec3 Position;
	glm::vec3 Size;  // Use this for scale
};

Modify the CheckCollision function to work with this struct:

bool CheckCollision(const Object &one, const Object &two) {
	// collision x-axis?
	bool collisionX = one.Position.x + one.Size.x >= two.Position.x &&
		two.Position.x + two.Size.x >= one.Position.x;
	// collision y-axis?
	bool collisionY = one.Position.y + one.Size.y >= two.Position.y &&
		two.Position.y + two.Size.y >= one.Position.y;
	// collision z-axis? (if 3D collision check is needed)
	bool collisionZ = one.Position.z + one.Size.z >= two.Position.z &&
		two.Position.z + two.Size.z >= one.Position.z;
	// collision only if on all axes
	return collisionX && collisionY && collisionZ;  // include collisionZ for 3D
}
Then, you can create Object instances using the positions and scales you extracted from your transformation matrices:

Object obj1 = { positionFromModelMamaAkam, scaleFromModelMamaAkam };
Object obj2 = { positionFromModelyMarix, scaleFromModelyMarix };

Finally, you can use the adapted CheckCollision function:

if (CheckCollision(obj1, obj2)) {
	// Collision detected
}
This way, you use the positions and scales extracted from the transformation matrices for collision checks.
***************************************************************** </Q2>
*/
   
/*
Q3/make mama akam move in random directions and rotate in circles 


A3/To make mamaAkam move in random directions and rotate in circles:

Initialize required variables for movement and rotation:

these are outside the main game loop, put in lines uder the #includes and  studd define them there...
float circleRadius = 10.0f;
float rotationSpeed = 0.05f;  // Adjust based on how fast you want the model to rotate
float angle = 0.0f;

glm::vec3 mamaAkamStartPosition = glm::vec3(10.0f, 1.0f, 10.0f);
glm::vec3 mamaAkamCurrentPosition = mamaAkamStartPosition;

// For random movement:
float moveSpeed = 0.5f;  // Adjust based on how fast you want the model to move
glm::vec3 randomDirection = glm::normalize(glm::vec3(rand() % 100 - 50, 0.0f, rand() % 100 - 50));
Inside the main rendering loop:
First, compute the position for circular movement:

cpp
Copy code
angle += rotationSpeed;
if (angle > 2 * 3.14159265f) {  // Reset angle if it goes beyond 360 degrees
    angle = 0.0f;
}

glm::vec3 circularOffset;
circularOffset.x = circleRadius * sin(angle);
circularOffset.z = circleRadius * cos(angle);

mamaAkamCurrentPosition += circularOffset;
Next, apply random movement:

cpp
Copy code
// Modify the position slightly in the random direction:
mamaAkamCurrentPosition += randomDirection * moveSpeed;

// Occasionally change the random direction:
if (rand() % 100 < 5) {  // 5% chance to change direction
    randomDirection = glm::normalize(glm::vec3(rand() % 100 - 50, 0.0f, rand() % 100 - 50));
}
Finally, set the model's position:

cpp
Copy code
modelMamaAkam = glm::translate(glm::mat4(1.0f), mamaAkamCurrentPosition);
Continue with the rest of your rendering code:
For example:

cpp
Copy code
modelMamaAkam = glm::rotate(modelMamaAkam, curAngle, glm::vec3(1.0f, -1.0f, 0.0f)); 
// ... [Rest of the code for rendering mamaAkam]
Remember to integrate the above snippets into your existing main loop. The model will now both revolve in a circle around the specified radius and move in random directions. Adjust the rotationSpeed, moveSpeed, and other parameters to tweak the behavior as desired.




User
thanks 
ChatGPT
You're welcome! If you have any more questions or need further assistance, feel free to ask. Happy coding!

*/






/* 
  
is it hard to do the rotation collision ? if the models hit while rotate?
ChatGPT
Detecting collisions between rotating objects, especially in 3D, can be quite complex, especially if you want accurate collision detection. There are a few methods and levels of detail you can pursue:

Bounding Spheres: This is the simplest form of collision detection. For each object, you compute a sphere that fully encloses the object. If the spheres of two objects overlap, you consider them to be colliding. The primary advantage is that the rotation doesn't change the bounding sphere. However, for non-spherical objects, this can be very imprecise.

Axis-Aligned Bounding Boxes (AABB): These are boxes that enclose the object but are aligned with the world or local axes. Checking collisions is quite fast, as you've shown in your previous code. However, when objects rotate, their AABBs can change dramatically and can be quite imprecise unless recomputed for every frame (which is costly).

Oriented Bounding Boxes (OBB): These are bounding boxes aligned with the object, not the world. This means they rotate with the object. Collision detection between two OBBs is more involved than AABBs but is more accurate for rotated objects.

Convex Hulls and Advanced Techniques: This involves creating a convex shell around the objects and checking for intersections. Methods like the Separating Axis Theorem (SAT) can be used for collision detection. It's much more accurate but also computationally intensive.

Mesh-level Collision: The most accurate collision detection would check for intersections at the mesh level. This involves checking if any triangles from one mesh intersect triangles from the other mesh. It's computationally expensive and typically used in scenarios where high accuracy is essential, like simulation or finite element analysis.

For games and most real-time graphics applications, you'll often use a combination of these techniques. Coarse methods (like bounding spheres or AABBs) can quickly rule out objects that are obviously not in contact, while more detailed methods (like OBB or SAT) can be used for objects that are closer to each other.

To implement rotating collision detection:

For Bounding Spheres: No change is needed when objects rotate.
For AABB: You can recompute the AABB after every rotation (expensive) or compute a larger AABB that takes into account all possible rotations (less accurate).
For OBB: Implement collision detection between two oriented boxes. This is a bit involved but offers a good balance between speed and accuracy.
For Convex Hulls: Use an algorithm like SAT.
For Mesh-level: Use a detailed mesh intersection algorithm.
If you're just starting out, I'd recommend sticking with AABB and, if rotation makes it imprecise, move to OBB. There are also physics libraries (like Bullet or PhysX) that handle these collision detections, if you want to dive deep into complex simulations.



User
AABB is it easy? like drwaing hypothetical boxes arouhnd the objects?
ChatGPT
Yes, AABB (Axis-Aligned Bounding Boxes) is relatively straightforward, and it's one of the simpler methods for collision detection. Here's the basic idea behind AABB:

Representation: For each object, you represent it with a hypothetical box that fully encloses the object. This box is "axis-aligned," meaning it doesn't rotate with the object. The box is defined by its minimum and maximum corners (min and max), which give the smallest and largest values for x, y, and z coordinates that enclose the object.

Collision Check: To check if two AABBs are colliding, you simply check if their boxes overlap in all three axes (x, y, z). If they overlap in all three axes, then the boxes (and therefore the objects) are colliding.

Here's a basic example:

cpp
Copy code
struct AABB {
	glm::vec3 min; // minimum corner
	glm::vec3 max; // maximum corner
};

bool CheckCollision(const AABB& a, const AABB& b) {
	return (a.min.x <= b.max.x && a.max.x >= b.min.x) &&
		   (a.min.y <= b.max.y && a.max.y >= b.min.y) &&
		   (a.min.z <= b.max.z && a.max.z >= b.min.z);
}
Limitations: The primary limitation with AABB is that, since the boxes don't rotate with the objects, they can become quite imprecise for rotated objects. For instance, consider a long, thin rectangle. If it rotates 45 degrees, its AABB might become much larger than the object itself.

Applications: Despite its simplicity and potential imprecision for certain rotations, AABB is widely used in many applications because it's fast. Often, it's used as a first-pass check to quickly rule out objects that are clearly not colliding. Objects that are determined to potentially be colliding based on their AABBs can then be checked using more detailed (but slower) methods if needed.

Creating AABB: If you know the geometry of your objects (e.g., you have access to the vertex data), you can compute the AABB by iterating over all vertices and finding the minimum and maximum values for x, y, and z. If your object is transformed (e.g., scaled, translated), you'll need to apply these transformations to the vertices first.

In essence, AABB is like drawing hypothetical non-rotating boxes around objects and checking if these boxes overlap to detect collisions.



User
I love it, and we don't need position and scale in this case? like we did for Object struct?
ChatGPT
Correct! When you're using AABB, you don't explicitly need separate position and scale as we discussed earlier with the GameObject struct. Instead, the AABB struct inherently represents the position and scale of the object through its min and max corners.

For example:

Position: The center of the AABB can be thought of as the object's position. It can be found as the midpoint between the min and max corners.

Scale: The dimensions of the AABB (width, height, depth) can be thought of as the object's scale. They can be found by subtracting the min corner from the max corner.

If you start with a base object that's defined at the origin (centered at (0,0,0)) with a scale of 1x1x1, and then you transform it (translate, scale, rotate), you'd compute its AABB in the transformed state. The resulting min and max corners would inherently account for the object's transformed position and scale.

However, remember that rotation isn't directly represented in AABB—since the bounding box is axis-aligned and doesn't rotate with the object. That's why, as previously mentioned, the AABB can become imprecise for objects that have been rotated significantly.

To create an AABB after transformations:

Apply the transformations to the object's vertices.
Iterate over the transformed vertices to find the minimum and maximum values for x, y, and z. These will become your AABB's min and max corners.
The main advantage of AABB is its simplicity and speed. By just looking at the min and max corners, you can quickly determine potential collisions.

User
wow just wow , I learn alot from you, OMG
ChatGPT
Thank you so much for the kind words! I'm thrilled to hear that you found the information helpful. Remember, learning, especially when it comes to programming and game development, is a journey. It's always great to see someone eager to learn and understand concepts. If you have any more questions or need clarification on any topic, don't hesitate to ask. Happy coding and game development! 😊🎮👾

User
I love it you exist Thank you
ChatGPT
Thank you for the kind sentiment! I'm here to help and guide you. Don't hesitate to return whenever you have questions or need assistance in the future. Happy coding and best wishes on all your projects! 🌟🚀

		


			
 Q4/
	ok how to use AABB (which means 'Axis-Aligned Bounding Box')  instead of previous 
	collision detection using poisition adn scale because it does not work.



	Answer 4/
	#include <iostream>
	#include <glm/glm.hpp> // Make sure to have this library available for vec3.

	// Define the Axis-Aligned Bounding Box structure.
	struct AABB {
	glm::vec3 min; // Minimum corner of the box.
	glm::vec3 max; // Maximum corner of the box.
	};

	// Check if two AABBs are colliding.
	bool CheckCollision(const AABB& a, const AABB& b) {
	// Check if box A's max is greater than box B's min and A's min is less than B's max.
	return (a.min.x <= b.max.x && a.max.x >= b.min.x) &&
		   (a.min.y <= b.max.y && a.max.y >= b.min.y) &&
		   (a.min.z <= b.max.z && a.max.z >= b.min.z);
		}

	int main() {
		// Define two AABBs. You need to replace these with your actual box corner positions.
		AABB obj1 = { glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(3.0f, 3.0f, 3.0f) }; // Replace with your values
		AABB obj2 = { glm::vec3(2.0f, 2.0f, 2.0f), glm::vec3(4.0f, 4.0f, 4.0f) }; // Replace with your values

		// Check for collision between the two AABBs.
		if (CheckCollision(obj1, obj2)) {
			std::cout << "Collision Detected!" << std::endl;
		}
		else {
		std::cout << "Collision is Not Detected!" << std::endl;
		}

		return 0; // Exit the application



		Q4/a/
		I already have the model1 glm::mat4
		modelyCat = glm::mat4(1.0f); //modely Seham atomaka
		//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(modelyCat));//<---this line
		modelyCat = glm::rotate(modelyCat, curAngle * 1, glm::vec3(0.0f, 0.1f, 0.0f));
		modelyCat = glm::scale(modelyCat, glm::vec3(0.04f, 0.04f, 0.04f));
		modelyCat = glm::translate(modelyCat, glm::vec3(0.0f, 0.0f, 1.0f)); and model2 glm::mat4 model(1.0f);
		model = glm::mat4(1.0f); //modely Yakam Atomaka
		model = glm::translate(model, glm::vec3(0.0f, 3.0f, -2.5f));
		model = glm::scale(model, glm::vec3(0.01f, 0.01f, 0.01f)); 

		A4/a/ 
			
			It seems like you're manipulating 3D models using transformations like scaling, rotation, and translation with the GLM library

			#include <glm/glm.hpp>
#include <vector>
#include <algorithm> // for minmax_element

struct AABB {
	glm::vec3 min; // Represents the lowest x, y, and z coordinates of the box.
	glm::vec3 max; // Represents the highest x, y, and z coordinates of the box.

	// You can also add constructors, methods, or operators here as needed.
	// For example, a method to calculate the center point might be useful.

	glm::vec3 center() const {
		return (min + max) * 0.5f; // Computes the center point of the box.
	}

	// Or a method to check if a point is inside the box.

	bool contains(const glm::vec3& point) const {
		return point.x >= min.x && point.x <= max.x &&
			   point.y >= min.y && point.y <= max.y &&
			   point.z >= min.z && point.z <= max.z;
	}

	// ... other utilities as needed
};  // ... ama hamwi la naw struct'akayan

	// Check if two AABBs are colliding.
	bool CheckCollision(const AABB& a, const AABB& b) {
	// Check if box A's max is greater than box B's min and A's min is less than B's max.
	return (a.min.x <= b.max.x && a.max.x >= b.min.x) &&
		   (a.min.y <= b.max.y && a.max.y >= b.min.y) &&
		   (a.min.z <= b.max.z && a.max.z >= b.min.z);
		}

// Given a list of vertices and a transformation matrix, find the AABB.
AABB calculateAABB(const std::vector<glm::vec3>& vertices, const glm::mat4& transform) {
	std::vector<glm::vec3> transformedVertices;

	// Transform all the model's vertices by the provided matrix.
	for (const auto& vertex : vertices) {
		glm::vec4 transformed = transform * glm::vec4(vertex, 1.0f);
		transformedVertices.push_back(glm::vec3(transformed));
	}

	// Find the minimum and maximum x, y, and z coordinates.
	auto [minIt, maxIt] = std::minmax_element(
		transformedVertices.begin(), transformedVertices.end(),
		[](const glm::vec3& a, const glm::vec3& b) {
			// Compare the sum of the coordinates.
			return a.x + a.y + a.z < b.x + b.y + b.z;
		}
	);

	AABB box;
	box.min = *minIt;
	box.max = *maxIt;
	return box;
}

// In your main function or wherever appropriate:

int main() {
	// Define your transformations here as you did with modelyCat and model.
	glm::mat4 modelyCatTransform =  ...;
	glm::mat4 modelTransform =  ... ;

	// Define your original model vertices here.
	std::vector<glm::vec3> modelyCatVertices = ...;
	std::vector<glm::vec3> modelVertices = .....;

	// Calculate AABBs.
	AABB box1 = calculateAABB(modelyCatVertices, modelyCatTransform);
	AABB box2 = calculateAABB(modelVertices, modelTransform);

	// Now you can use your CheckCollision function to test for collisions.
	if (CheckCollision(box1, box2)) {
		std::cout << "Collision Detected!" << std::endl;
	}
	else {
		std::cout << "Collision is Not Detected!" << std::endl;
	}

	return 0;
}


	Q4/b/		
		in the auto [minIt .... minIt and maxIt are undefined.



	A4/b/	
		requires C++17 or later.
		Visual Studio: Go to the project properties,
		then go to Configuration Properties -> C/C++ -> Language -> C++ Language Standard, 
		and select /std:c++17 or higher.
		

	Q4/c/ 
		in the previous answer , you said  // Define your transformations here as you did with modelyCat and model.
		glm::mat4 modelyCatTransform =  ...; how do you mean ? can you give me a hint ?


	A4/c/
		transformation is your scaling and rotating etc...
		
		// Initialize to identity matrix; no transformation
		glm::mat4 modelyCatTransform = glm::mat4(1.0f);

		// Apply transformations:
		// 1. Scale: If your object is too large or too small, you might want to scale it.
		modelyCatTransform = glm::scale(modelyCatTransform, glm::vec3(0.5f, 0.5f, 0.5f)); // Scale by 0.5 on all axes

		// 2. Rotate: If your object is facing the wrong direction or needs to be oriented properly.
		// The rotation is in radians, and you specify the axis to rotate around.
		modelyCatTransform = glm::rotate(modelyCatTransform, glm::radians(45.0f), glm::vec3(0.0f, 1.0f, 0.0f)); // Rotate 45 degrees around the y-axis

		// 3. Translate: If your object is not in the correct location, you move it.
		modelyCatTransform = glm::translate(modelyCatTransform, glm::vec3(10.0f, 0.0f, 5.0f)); // Move the object to (10, 0, 5)

		Q4/d/
		so transformation is a word used for (scale, rotate, translate)? or there are more?

		A4/d/
		there are others like Non-Uniform Scaling:
		glm::mat4 myMatrix = glm::mat4(1.0f);  // Start with the identity matrix

			// Define different scaling factors for each axis
			float scaleX = 1.0f;
			float scaleY = 2.0f; // Y dimension is doubled, stretching the object vertically
			float scaleZ = 0.5f; // Z dimension is halved, compressing the object depth-wise

			// Create the scaling matrix
			myMatrix = glm::scale(myMatrix, glm::vec3(scaleX, scaleY, scaleZ));

		and there is like for example Shearing:
				Shearing is a transformation that shifts points in a fixed direction, altering
				the object's shape, often turning squares into parallelograms or altering objects in more complex ways.
			glm::mat4 myMatrix = glm::mat4(1.0f);  // Start with the identity matrix

				// Define shear factors
				float shearXY = 0.3f; // shearing factor in the XY direction
				float shearXZ = 0.0f; // no shearing in XZ direction
				float shearYX = 0.0f; // no shearing in YX direction
				float shearYZ = 0.0f; // no shearing in YZ direction
				float shearZX = 0.0f; // no shearing in ZX direction
				float shearZY = 0.0f; // no shearing in ZY direction

				// Construct a shearing matrix
				glm::mat4 shearMatrix(1.0f);
				shearMatrix[1][0] = shearYX; // shearing in the YX direction
				shearMatrix[1][2] = shearYZ; // shearing in the YZ direction
				shearMatrix[2][0] = shearZX; // shearing in the ZX direction
				shearMatrix[2][1] = shearZY; // shearing in the ZY direction
				shearMatrix[0][1] = shearXZ; // shearing in the XZ direction
				shearMatrix[0][2] = shearXY; // shearing in the XY direction

				// Apply the shear transformation
				myMatrix *= shearMatrix;


			Translation: Moves an object from one place to another along a straight line.
			It's defined by a direction and distance.

			Rotation: Changes the orientation of an object about an axis.

			Scaling: Increases or decreases the size of an object. Scaling can be uniform 
			(the same amount in all directions) or non-uniform (different amounts in different directions).

			These three (Translation,Rotation,Scaling) are the foundational transformations, but there are more advanced or specific types of 
			transformations used in various applications:

			Shear: Shifts the shape of an object by pushing points in parallel directions. 
			Unlike the basic transformations, it distorts the object's shape. For example,
			it can turn a square into a parallelogram.

			Reflection: Creates a mirror image of an object across a plane.

			Perspective transformations: These are essential for 3D rendering 
			because they simulate the way objects appear smaller as they get further 
			from the viewer. They're used to convert the 3D view into a 2D projection on the screen.

			Affine transformations: These preserve points, straight lines, and planes. 
			Sets of parallel lines remain parallel after an affine transformation. 
			The term "affine transformation" encompasses various transformations, 
			including translation, scaling, rotation, reflection, and shearing.

			Non-uniform scaling: This involves scaling an object by different amounts 
			in different directions. For example, you could stretch an object more horizontally than vertically, 
			changing its shape.

			Composite transformations: (Often, multiple transformations are combined to create a final effect),
			done by multiplying the matrices representing the individual transformations.
			The order of these operations is crucial.

		Q4/e/
			ALright, in previous answer you said '  // Define your original model vertices here.
			std::vector<glm::vec3> modelyCatVertices =  ... ;
			std::vector<glm::vec3> modelVertices =   ...  ;
			but I already have these
			Mesh* obj1 = new Mesh(); //initialize everything to zero VBO = 0 .... etc
			obj1->createMesh(vertices, indices, 32, 12); // 12 vertices for now
			MeshList.push_back(obj1);

			Mesh* obj2 = new Mesh(); //initialize everything to zero VBO = 0 .... etc
			obj2->createMesh(vertices, indices, 32, 12); // 12 vertices for now
			MeshList.push_back(obj2); 

			And here is my Mesh.h and Mesh.cpp code (copy paste both)

	
		A4/e/
			Certainly, I understand you're working with a fairly encapsulated mesh system where each mesh's data is stored in GPU buffers (like VBO for vertices and IBO for indices), and you don't maintain a copy of the vertex data in your system memory. For operations that require direct access to vertex data (like calculating AABB or collision detection), you would need to have access to this data within your system's memory.

			Given your current class design, you don't store that data within your Mesh class, and OpenGL doesn't allow reading back from VBOs efficiently. To work with this, you'll have to modify your class to also store a copy of the vertices. I'll provide a simplified example of how you might adjust your Mesh class.

			Here's how you might modify your class definition (in your Mesh.h):


			#include <vector>
			#include <GL/glew.h>
			#include <glm/vec3.hpp> // glm::vec3

			class Mesh {
			public:
			Mesh();

				void createMesh(const GLfloat* vertices, const unsigned int* indices, unsigned int numOfVertices, unsigned int numOfIndices);
				void RenderMesh();
				void clearMesh();

				// New method to get the vertices.
				const std::vector<glm::vec3>& getVertices() const { return storedVertices; }

				~Mesh();

			private:
				GLuint VAO, VBO, IBO;
				GLsizei indexCount;
				GLenum error;

				// New member to store the vertex data.
				std::vector<glm::vec3> storedVertices;
			};

			And in your Mesh.cpp, you'd modify your createMesh function to fill this new vector. You'll have to parse the vertex positions from your input
			array because it seems like you're interlacing vertex data (positions, texture coordinates, normals, etc.):
			
			#include "Mesh.h"
			#include <iostream>
			#include <glm/vec3.hpp> // glm::vec3

			// ... other methods remain unchanged ...

			void Mesh::createMesh(const GLfloat * vertices, const unsigned int* indices, unsigned int numOfVertices, unsigned int numOfIndices) {
				// Existing setup code...
				// ...

				// After uploading data to the GPU, also store vertex positions in your class
				storedVertices.clear();
				for (unsigned int i = 0; i < numOfVertices; i += 8) {  // Assuming 8 GLfloats per vertex
					storedVertices.emplace_back(vertices[i], vertices[i + 1], vertices[i + 2]);
				}

				// The rest of your method...
				// ...
			}

			<Q5 And A5>
			In this code, I have problem when I retrieve vertices it does not appear to be defined, I have the verticesObj1 and verticesObj2 etc in the createObject function , void CreateObjects() { unsigned int indices[] = { 0, 3, 1, 1, 3, 2, 2, 3, 0, 0, 1, 2 }; GLfloat vertices[] = { // x   y   z u  v nx  ny  nz -1.0f, -1.0f, -0.6f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, -1.0f, 1.0f, 0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, -1.0f, -0.6f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.5f, 1.0f, 0.0f, 0.0f, 0.0f }; const int segments = 1; // Number of segments around the sphere const int rings = 1;  // Number of rings from top to bottom GLfloat sphereVertices[(segments + 1) * (rings + 1) * 8]; unsigned int sphereIndices[segments * rings * 6]; unsigned int floorIndices[] = { 0, 1, 2, // first triangle 2, 1, 3, // second triangle 4, 5, 6, // third triangle 6, 5, 7, // fourth triangle // add more triangles as needed... }; GLfloat floorVertices[] = { // vertex 0 -1000.0f, -1.0f, -1000.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, // vertex 1 1000.0f, -1.0f, -1000.0f, 1000.0f, 0.0f, 0.0f, 1.0f, 0.0f, // vertex 2 -1000.0f, -1.0f, 1000.0f, 0.0f, 1000.0f, 0.0f, 1.0f, 0.0f, // vertex 3 1000.0f, -1.0f, 1000.0f, 1000.0f, 1000.0f, 0.0f, 1.0f, 0.0f, // vertex 4 -1000.0f, -1.0f, -1000.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, // vertex 5 1000.0f, -1.0f, -1000.0f, 1000.0f, 0.0f, 0.0f, 1.0f, 0.0f, // vertex 6 -1000.0f, -1.0f, 1000.0f, 0.0f, 1000.0f, 0.0f, 1.0f, 0.0f, // vertex 7 1000.0f, -1.0f, 1000.0f, 1000.0f, 1000.0f, 0.0f, 1.0f, 0.0f }; GLfloat floorVertices2[] = { //50 Vertices // vertex 0 -50.0f, -1.0f, -50.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, // vertex 1 50.0f, -1.0f, -50.0f, 50.0f, 0.0f, 0.0f, 1.0f, 0.0f, // vertex 2 -50.0f, -1.0f, 50.0f, 0.0f, 50.0f, 0.0f, 1.0f, 0.0f, // vertex 3 50.0f, -1.0f, 50.0f, 50.0f, 50.0f, 0.0f, 1.0f, 0.0f, // vertex 4 -50.0f, -1.0f, -50.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, // vertex 5 50.0f, -1.0f, -50.0f, 50.0f, 0.0f, 0.0f, 1.0f, 0.0f, // vertex 6 -50.0f, -1.0f, 50.0f, 0.0f, 50.0f, 0.0f, 1.0f, 0.0f, // vertex 7 50.0f, -1.0f, 50.0f, 50.0f, 50.0f, 0.0f, 1.0f, 0.0f }; GLfloat houseVertices[] = { // Base -2.0f, 0.0f, -2.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, -2.0f, 0.0f, 2.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 2.0f, 0.0f, 2.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f, 2.0f, 0.0f, -2.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, // Walls -2.0f, 0.0f, -2.0f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f, -2.0f, 4.0f, -2.0f, 0.0f, 1.0f, -1.0f, 0.0f, 0.0f, 2.0f, 4.0f, -2.0f, 1.0f, 1.0f, -1.0f, 0.0f, 0.0f, 2.0f, 0.0f, -2.0f, 1.0f, 0.0f, -1.0f, 0.0f, 0.0f, -2.0f, 0.0f, -2.0f, 0.0f, 0.0f, 0.0f, 0.0f, -1.0f, -2.0f, 0.0f, 2.0f, 0.0f, 1.0f, 0.0f, 0.0f, -1.0f, -2.0f, 4.0f, 2.0f, 1.0f, 1.0f, 0.0f, 0.0f, -1.0f, -2.0f, 4.0f, -2.0f, 1.0f, 0.0f, 0.0f, 0.0f, -1.0f, 2.0f, 0.0f, -2.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 2.0f, 4.0f, -2.0f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, // Roof -2.0f, 4.0f, -2.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, -2.0f, 4.0f, 2.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,  2.0f, 4.0f, 2.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f,  2.0f, 4.0f, -2.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f }; // add more vertices as needed... unsigned int houseIndices[] = { // Base 0, 1, 2, 0, 2, 3, // Walls 4, 5, 6, 4, 6, 7, 8, 9, 10, 8, 10, 11, 4, 5, 9, 4, 9, 8, 6, 7, 11, 6, 11, 10, // Roof 1, 5, 9, 1, 9, 2, 3, 2, 10, 3, 10, 11 }; calcAverageNormals(indices, 12, vertices, 32, 8, 5); Mesh* obj1 = new Mesh(); //initialize everything to zero VBO = 0 .... etc  obj1->createMesh(vertices, indices, 32, 12); // 12 vertices for now MeshList.push_back(obj1); //obj1->getVertices(); const std::vector<glm::vec3>& shpereVerticy = obj1->getVertices(); for (const auto& shpereVerticy : shpereVerticy) { std::cout << "Vertex : shpereVerticy.x shpereVerticy.y shpereVerticy.z (" << shpereVerticy.x << " " << shpereVerticy.y << " " << shpereVerticy.z << ")" << std::endl; } const std::vector<glm::vec3>& verticesObj1 = obj1->getVertices(); Mesh* obj2 = new Mesh(); //initialize everything to zero VBO = 0 .... etc  obj2->createMesh(vertices, indices, 32, 12); // 12 vertices for now MeshList.push_back(obj2); const std::vector<glm::vec3>& verticesObj2 = obj2->getVertices(); //const std::vector<glm::vec3>& verticesObj2 = obj2->getVertices(); float radius = 10.0f; int sectorCount = 720; int stackCount = 240; CreateSphere(radius, sectorCount, stackCount); const std::vector<glm::vec3>& segosha = obj2->getVertices(); for (const auto& vertex : segosha) { std::cout << "Vertex : vertex.x vertex.y vertex.z (" << vertex.x << " " << vertex.y << " " << vertex.z << ")" << std::endl; } Mesh* house = new Mesh(); // house->createMesh(houseVertices, houseIndices, 32, 6); //  MeshList.push_back(house); const std::vector<glm::vec3>& verticeshouse = house->getVertices(); skyBox vert1; Mesh* obj3 = new Mesh(); //initialize everything to zero VBO = 0 .... etc  obj3->createMesh(vertices, indices, 32, 12); // 12 vertices for now MeshList.push_back(obj3); const std::vector<glm::vec3>& verticesObj3 = obj3->getVertices(); //bo modely cataka Maybe 'lawanaya ama be' const std::vector<glm::vec3>& catVerticy = obj3->getVertices(); Mesh* obj4 = new Mesh(); //initialize everything to zero VBO = 0 .... etc  obj4->createMesh(vertices, indices, 32, 12); // 12 vertices for now MeshList.push_back(obj4); const std::vector<glm::vec3>& verticesObj4 = obj4->getVertices(); std::cout << "\033[1mVertices🌟🚀\033[0m (\033[31m" << *sphereVertices << "\033[0m): \033[1mTriangles🌟🚀\033[0m (\033[35m" << *sphereVertices / 3 << "\033[0m)" << std::endl; std::cout << "\033[1mhouseVertices\033[0m (\033[31m" << *houseVertices << "\033[0m): \033[1mhouseIndices\033[0m (\033[35m" << *houseIndices << "\033[0m)" << std::endl; std::cout << "\033[1mhouseVertices\033[0m (\033[31m" << catVerticy.size() << "\033[0m): \033[1mhouseIndices\033[0m (\033[35m"; } how to get/retrieve the verticesObj1 and verticesObj2 in game loop for AABB ? here is the rest class GameObject { public: glm::vec3 Position; glm::vec3 Size; // Add other attributes if needed GameObject(glm::vec3 pos, glm::vec3 size) : Position(pos), Size(size) {} }; // *******struct Object struct Object { glm::vec3 Position; glm::vec3 Size; // Use this for scale }; struct AABB { glm::vec3 min; // The minimum corner of the bounding box. glm::vec3 max; // The maximum corner of the bounding box. }; // vector <glm::vec3> & shtek; //Bo nmwna  AABB calculateAABB(const std::vector<glm::vec3> &vertices, const glm::mat4& transform) {  std::vector<glm::vec3> transformedVertices; // Transform all the model's vertices by the provided matrix. for (const auto& vertex : vertices) { glm::vec4 transformed = transform * glm::vec4(vertex, 1.0f); transformedVertices.push_back(glm::vec3(transformed)); } // Find the minimum and maximum x, y, and z coordinates. auto [minIt, maxIt] = std::minmax_element( transformedVertices.begin(), transformedVertices.end(), [](const glm::vec3& a, const glm::vec3& b) { // Compare the sum of the coordinates. return a.x + a.y + a.z < b.x + b.y + b.z; } ); AABB box; box.min = *minIt; box.max = *maxIt; return box; } bool CheckCollision(const Object& one, const Object& two) { // collision x-axis? bool collisionX = one.Position.x + one.Size.x >= two.Position.x &&  two.Position.x + two.Size.x >= one.Position.x;  // collision y-axis? bool collisionY = one.Position.y + one.Size.y >= two.Position.y && two.Position.y + two.Size.y >= one.Position.y; // collision z-axis? (if 3D collision check is needed) bool collisionZ = one.Position.z + one.Size.z >= two.Position.z && two.Position.z + two.Size.z >= one.Position.z; // collision only if on all axes return collisionX && collisionY && collisionZ; // include collisionZ for 3D } int main() { CreateObjects(); while (!mainWindow.getShouldclose()) { glm::mat4 model(1.0f); model = glm::mat4(1.0f); //modely Yakam Atomaka model = glm::translate(model, glm::vec3(0.0f, 3.0f, -2.5f)); model = glm::scale(model, glm::vec3(0.01f, 0.01f, 0.01f)); AABB box1 = calculateAABB(verticyobj1, model); AABB box2 = calculateAABB(transformedmodel, model2); You see that transformedmodel? This gives error undefined , and the purpose is for AABB collision detection between two specific models

Neo
A// Bard//
// In the game loop:

// Get the Mesh objects for obj1 and obj2.
Mesh* obj1 = MeshList[0]; // This assumes that obj1 is the first object in the MeshList.
Mesh* obj2 = MeshList[1]; // This assumes that obj2 is the second object in the MeshList.

// Get the vertices of obj1 and obj2.
const std::vector<glm::vec3>& verticesObj1 = obj1->getVertices();
const std::vector<glm::vec3>& verticesObj2 = obj2->getVertices();

// Calculate the AABB of obj1 and obj2.
AABB box1 = calculateAABB(verticesObj1, obj1->modelMatrix);
AABB box2 = calculateAABB(verticesObj2, obj2->modelMatrix);

// Check for collision between obj1 and obj2.
bool isColliding = CheckCollision(box1, box2);

// In the game loop:

// Get the Mesh objects for obj1 and obj2.
Mesh* obj1 = MeshList[0]; // This assumes that obj1 is the first object in the MeshList.
Mesh* obj2 = MeshList[1]; // This assumes that obj2 is the second object in the MeshList.

// Get the vertices of obj1 and obj2.
const std::vector<glm::vec3>& verticesObj1 = obj1->getVertices();
const std::vector<glm::vec3>& verticesObj2 = obj2->getVertices();

// Calculate the AABB of obj1 and obj2.
AABB box1 = calculateAABB(verticesObj1, obj1->modelMatrix);
AABB box2 = calculateAABB(verticesObj2, obj2->modelMatrix);

// Check for collision between obj1 and obj2.
bool isColliding = CheckCollision(box1, box2);

// If obj1 and obj2 are colliding, do something.
if (isColliding) {
  // TODO: Handle collision
}

// In the game loop:

// Get the Mesh object for obj2.
Mesh* obj2 = MeshList[1]; // This assumes that obj2 is the second object in the MeshList.

// Transform the vertices of obj2 by the model matrix.
std::vector<glm::vec3> transformedModel;
for (const auto& vertex : obj2->getVertices()) {
  transformedModel.push_back(obj2->modelMatrix * glm::vec4(vertex, 1.0f));
}

// Calculate the AABB of obj2.
AABB box2 = calculateAABB(transformedModel, obj2->modelMatrix);

Full Doc
https://docs.google.com/document/u/0/d/1kpxixvbTeuzJBTx5Glx7LgENcku_7ylFRE3OHGmIAGw/mobilebasic?pli=1

			</Q5 And A5>

*/


/*
 ***********<NOTE>****************
					**** This is how it works ****
					glm::mat4 model1 = glm::mat4(1.0f);
					 model1 = glm::translate(model1, position1);
					 model1 = glm::rotate(model1, angle1, rotationAxis1);
					 // <-- Update the uniform
					// ... render model1 ...

					glm::mat4 model2 = glm::mat4(1.0f);
					model2 = glm::translate(model2, position2);
					model2 = glm::rotate(model2, angle2, rotationAxis2);
					// <-- Update the uniform
					... render model2 ...

		 This Is Exactly How You Do It With Updating the uniform:....

		 glm::mat4 model1 = glm::mat4(1.0f);
		model1 = glm::translate(model1, position1);
		model1 = glm::rotate(model1, angle1, rotationAxis1);
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model1));  // <-- Update the uniform
		// ... render model1 ...

		glm::mat4 model2 = glm::mat4(1.0f);
		model2 = glm::translate(model2, position2);
		model2 = glm::rotate(model2, angle2, rotationAxis2);
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model2));  // <-- Update the uniform again for model2
		// ... render model2 ...

		************</NOTE>***************

*/