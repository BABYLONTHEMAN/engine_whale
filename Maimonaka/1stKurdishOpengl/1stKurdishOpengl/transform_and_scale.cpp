//// Assumed predefined variables or dynamically calculated values for each model
//// For modelyCat
//glm::vec3 positionCat = ...; // Unique position for modelyCat
//float rotationAngleCat = ...; // Unique rotation for modelyCat
//glm::vec3 scaleCat = ...; // Unique scale for modelyCat
//
//// For modelyMarix
//glm::vec3 positionMarix = ...; // Unique position for modelyMarix
//float rotationAngleMarix = ...; // Unique rotation for modelyMarix
//glm::vec3 scaleMarix = ...; // Unique scale for modelyMarix
//
//// Calculate transformation matrix for modelyCat
//glm::mat4 modelyCat = glm::mat4(1.0f);
//modelyCat = glm::translate(modelyCat, positionCat);
//modelyCat = glm::rotate(modelyCat, glm::radians(rotationAngleCat), glm::vec3(0.0f, 1.0f, 0.0f));
//modelyCat = glm::scale(modelyCat, scaleCat);
//
//// Update shader with modelyCat's transformation matrix and render it
//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(modelyCat));
//// Render modelyCat ...
//
//// Calculate transformation matrix for modelyMarix
//glm::mat4 modelyMarix = glm::mat4(1.0f);
//modelyMarix = glm::translate(modelyMarix, positionMarix);
//modelyMarix = glm::rotate(modelyMarix, glm::radians(rotationAngleMarix), glm::vec3(0.0f, 1.0f, 0.0f));
//modelyMarix = glm::scale(modelyMarix, scaleMarix);
//
//// Update shader with modelyMarix's transformation matrix and render it
//glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(modelyMarix));
//// Render modelyMarix ...
//
//
//
//c++
//Copy code
//glm::mat4 model = glm::mat4(1.0f); // Starting with an identity matrix
//glm::vec3 scaleModel(0.01f, 0.01f, 0.01f); // Initial scale factors
//model = glm::scale(model, scaleModel); // Apply initial scaling
//Update Scaling on Event (e.g., collision): If an event occurs where you need to update the model's scale (like a collision), you need to define a new scale vector and reapply the scaling to either a reset or the current transformation matrix, depending on whether you want the scaling to be cumulative or absolute.
//
//For Absolute Scaling (Replacing Previous Scale):
//
//c++
//Copy code
//// Assuming a collision or any condition is detected
//scaleModel = glm::vec3(0.003f, 0.003f, 0.003f); // Update scale factors
//model = glm::mat4(1.0f); // Reset to identity matrix if you don't want cumulative transformations
//model = glm::scale(model, scaleModel); // Reapply new scaling
//For Cumulative Scaling (Adding to Previous Scale):
//
//c++
//Copy code
//// Assuming a collision or any condition is detected
//glm::vec3 additionalScale(0.003f, 0.003f, 0.003f); // Define additional scale factors
//model = glm::scale(model, additionalScale); // Apply additional scaling on top of existing transformations
//Note: If the scale change is intended to be permanent (i.e., not just a temporary effect during a collision), you would update the scaleModel variable and then reapply it with glm::scale as shown above. Always remember, the transformation matrix (model in your case) does not dynamically link to the scale vector (scaleModel), so changes to the vector require a manual update to the transformation matrix.
//
//
