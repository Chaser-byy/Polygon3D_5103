#pragma once
#ifndef _CONFIG_H
#define _CONFIG_H

struct Config
{
	const float InitWindowWidth  = 1290.0f;
	const float InitWindowHeight = 960.0f ;
	float WindowX = InitWindowWidth;
	float WindowY = InitWindowHeight;
	float fov = 45.0f;
};

#endif
