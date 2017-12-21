/*
 MIT License
 
 Copyright (c) 2017 SAE Institute Switzerland AG
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in all
 copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 SOFTWARE.
 */

#include <engine/component.h>
#include <engine/log.h>
#include <string>
namespace mmgga
{

Component::Component(GameObject& parentObject) :
	gameObject(parentObject)
{
	
}

Transform* Transform::LoadTransform(json transformJson, GameObject& parentGameObject)
{
	Transform* newTransform = new Transform(parentGameObject);
	newTransform->SetPosition(sf::Vector2f(transformJson["position"][0], transformJson["position"][1]));
	newTransform->SetScale(sf::Vector2f(transformJson["scale"][0], transformJson["scale"][1]));
	newTransform->SetEulerAngle(transformJson["eulerAngle"]);

	mmgga::Log::GetInstance()->Msg("EulerAngler: " + std::to_string(newTransform->GetEulerAngle()));
	mmgga::Log::GetInstance()->Msg("Scale: x: " + std::to_string(newTransform->GetScale().x) + " y: " + 
		std::to_string(newTransform->GetScale().y));
	mmgga::Log::GetInstance()->Msg("Position: x: " + std::to_string(newTransform->GetPosition().x) + " y: " +
		std::to_string(newTransform->GetPosition().y));

	return newTransform;
}

void Transform::Update(sf::Time dt)
{

}

float Transform::GetEulerAngle()
{
	return eulerAngle;
}

void Transform::SetEulerAngle(float eulerAngle)
{
	this->eulerAngle = eulerAngle;
}

sf::Vector2f Transform::GetPosition()
{
	return position;
}

void Transform::SetPosition(sf::Vector2f position)
{
	this->position = position;
}

sf::Vector2f Transform::GetScale()
{
	return scale;
}

void Transform::SetScale(sf::Vector2f scale)
{
	this->scale = scale;
}
}
