import { INCREMENT, DECREMENT, RESET } from "../ations/actionTypes.js";



//fuctions will be called something like 
//counterReducer(currentState,{type:typeofaction})
//counterReducer(10,{type:INCREMENT})
//counterReducer(10,{type:DECREMENT})
//counterReducer(10,{type:RESET})

const initialState = 0;

const counterReducer = (state=initialState,action) => {

        switch(action.type){
            case INCREMENT : return state + action.value
            case DECREMENT : return state - 1
            case RESET :      return initialState
            default : return state;
        }
}


export default counterReducer






