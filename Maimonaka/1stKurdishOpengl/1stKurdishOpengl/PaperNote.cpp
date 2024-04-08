//PaperNote
//

//Note1
// Example transformation for a model
/*
    glm::mat4 model = glm::mat4(1.0f);
    // Scale, then rotate, then translate
    model = glm::translate(model, glm::vec3(xPos, yPos, zPos));
    model = glm::rotate(model, glm::radians(rotationAngle), glm::vec3(0.0f, 1.0f, 0.0f));
    model = glm::scale(model, glm::vec3(scaleX, scaleY, scaleZ));
    // Now send the model matrix to your shader
    glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));

    // Render your model
*/

//Note2
/*
this project, the terrain's height can be changed in two ways:

 using
1:model3arz = glm::scale(model3arz, glm::vec3(1.01f, -10.01f, -3.01f));

2:in the gpuHeightT.tese in this line 'Height = texture(heightMap, texCoord).y * 3.8 - 0.5;' those two numbers


*/

//Note3
//create unique transformations for every model
/*
    glm::mat4 model(1.0f);
        glm::vec3 scaleyModel(0.01f, 0.01f, 0.01f); // Define scale factors
        glm::vec3 translateModel(0.0f, -3.0f, -2.5f);
        //have to update
        model = glm::scale(model, scaleyModel); // Apply scaling to the transformation matrix
        model = glm::translate(model,translateModel);

        //lets say after some Line of code, need to change it again
            scaleyModel = glm::vec3(0.01f, 0.01f, 0.01f);  // Define scale factors again
		    translateModel = glm::vec3(0.0f, -3.0f, -2.5f);//Define translateModel again ////Ashtwani bley glm::vec3 traModel1Rand(RandxPos / 1000, 0.0f, 0.0f);
		
		//'you have to update again:
		    model = glm::scale(model, scaleyModel); // Apply scaling to the transformation matrix 
		    model = glm::translate(model, translateModel);




        //bo swranaway wakw zawy badawri shteka Radius habe, ba (translate akre) //wakw solar system:
            modelyMarix = glm::translate(modelyMarix, glm::vec3(RandzPos/3, 0.1f, zPos / 4)); 
        //rotate bas ba dawri xoya aswretawa 'radius = 0' 
*/

//Note4
/*
* IMPORTANT
Image textures .png that comes with .obj files MUST be 1280 X 720 otherwise NOT working

*/