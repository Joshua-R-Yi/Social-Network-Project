#include "post.h"

Post::Post(){
    messageId_ = 0;
    ownerId_ = 0;
    message_ = "";
    likes_ = 0;
}


Post::Post(int messageId, int ownerId, std::string message, int likes){
    messageId_ = messageId;
    ownerId_ = ownerId;
    message_ = message;
    likes_ = likes;
}


std::string Post::toString(){return message_ + " Liked by " + std::to_string(likes_) + " people.";}


int Post::getMessageId(){ return messageId_; }


int Post::getOwnerId(){ return ownerId_; }


std::string Post::getMessage(){ return message_; }


int Post::getLikes(){ return likes_; }

// Virtual
std::string Post::getAuthor(){ return ""; }

// Virtual
bool Post::getIsPublic(){ return true; }





IncomingPost::IncomingPost() : Post::Post(){}


IncomingPost::IncomingPost(int messageId, int ownerId, std::string message, int likes, bool isPublic, std::string author) : Post::Post(messageId, ownerId, message, likes){
    isPublic_ = isPublic;
    author_ = author;
}


std::string IncomingPost::toString(){
    return author_ + " wrote" + (isPublic_ ? "" : " (private)") + ": " + Post::toString();
}


std::string IncomingPost::getAuthor(){ return author_; }


bool IncomingPost::getIsPublic(){ return isPublic_; }

