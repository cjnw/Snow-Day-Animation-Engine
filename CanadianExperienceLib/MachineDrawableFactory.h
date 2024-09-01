/**
 * @file MachineDrawableFactory.h
 * @author CJ Nwogu
 *
 *
 */

#ifndef CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_MACHINEDRAWABLEFACTORY_H
#define CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_MACHINEDRAWABLEFACTORY_H

class Actor;

/**
 * Factory for our machine drawable
 */
class MachineDrawableFactory
{
private:

public:
    std::shared_ptr<Actor> Create(std::wstring imagesDir);

};

#endif //CANADIANEXPERIENCE_CANADIANEXPERIENCELIB_MACHINEDRAWABLEFACTORY_H
