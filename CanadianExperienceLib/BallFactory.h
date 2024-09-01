/**
 * @file BallFactory.h
 * @author CJ Nwogu
 *
 *
 */

#ifndef CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_BALLFACTORY_H
#define CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_BALLFACTORY_H

class Actor;

/**
 * Factory class to create ball
 */
class BallFactory
{
private:

public:
    std::shared_ptr<Actor> Create(std::wstring imagesDir);

};

#endif //CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_BALLFACTORY_H

