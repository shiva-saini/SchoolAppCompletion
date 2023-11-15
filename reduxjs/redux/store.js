import { createStore } from "redux";
import counterReducer from "./reducer/counterReducer.js";

const store = createStore(counterReducer)

export default store



//store.dispatch(increment())
// it will first call increment function and increment function will give obj {type:"INCREMENT"}
// now this obj will be passed to counterReducer
// counterReducer(currentState,obj) == counterReducer(state,{type:"INCREMENT"})
// reducer will run switch case code and perform the operation based on type
// now this will increment the value of current state variable


// store.dispatch(increment(value))
// it will first call increment funtion with value that means increment function should accept it
// increment function will return an object wiht value and pass it to counterReducer so cunter reducer should accept object wiht value 
// reducer will ren switch case code and perform the operation based on type and return the state value
// now state value will change and will be returned to store
// now store will return it in app.js