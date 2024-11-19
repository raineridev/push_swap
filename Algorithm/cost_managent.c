/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_managent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraineri <mraineri@studenbt.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 21:22:52 by mraineri          #+#    #+#             */
/*   Updated: 2024/11/13 15:32:45 by mraineri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.c"

void logText(ps_lst *stack_a, ps_lst *stack_b) 
{
    ps_lst *tmp = stack_a;
    printf("===================\n");
    printf("\e[44m NODES(STACK A) WITH INDEX \e[49m\n");
    while(tmp)
    {
        printf("Node -> [%d]%d\n", tmp->index, tmp->num); 
        tmp = tmp->next;
    }
    tmp = stack_b;
    printf("===================\n");
    printf("\e[44m NODES(STACK B) WITH INDEX \e[49m\n");
    while(tmp)
    {
        printf("Node -> [%d]%d\n", tmp->index, tmp->num); 
        tmp = tmp->next;
    }
    printf("===================\n");
    printf("\e[42m TARGET NODES \e[49m\n");
    tmp = stack_a;
    while(tmp)
    {
        printf("Node -> [%d]%d  -? [%d]%d\n", tmp->index, tmp->num, tmp->target->index, tmp->target->num); 
        tmp = tmp->next;
    }
    printf("===================\n");
    printf("\e[43m COST NODES(STACK A) \e[49m\n");
    tmp = stack_a;
    while(tmp)
    {
        printf("Node -> [%d]%d | Cost -> %d\n", tmp->index, tmp->num, tmp->cost); 
        tmp = tmp->next;
    }
    printf("===================\n");
    printf("\e[43m COST NODES(STACK B) \e[49m\n");
    tmp = stack_b;
    while(tmp)
    {
        printf("Node -> [%d]%d | Cost -> %d\n", tmp->index, tmp->num, tmp->cost); 
        tmp = tmp->next;
    }
    printf("===================\n");
    printf("\e[45m COST NODES TOTAL COST(STACK A) \e[49m\n");
    tmp = stack_a;
    while(tmp)
    {
        printf("Node -> [%d]%d -. [%d]%d  Total Cost -> %d\n", tmp->index, tmp->num,tmp->target->index, tmp->target->num, (tmp->cost + tmp->target->cost)); 
        tmp = tmp->next;
    }
}

void	ps_target(ps_lst *stack_a, ps_lst *stack_b)
{
    ps_lst  *tmp_a;
    
    if (!stack_a || !stack_b)
        return;
    tmp_a = stack_a;
    while(tmp_a)
    {
        tmp_a->target = ps_soon(tmp_a, stack_b);
        tmp_a = tmp_a->next;
    }
}

void redefine_index(ps_lst *stack_a, ps_lst *stack_b)
{
    ps_lst  *tmp_a;
    ps_lst  *tmp_b;
	int i;

    tmp_a = stack_a;
    tmp_b = stack_b;
	i = 0;
    if(tmp_a->prev || tmp_b->prev)
    {
        while(tmp_a->prev)
            tmp_a = tmp_a->prev;
        while(tmp_b->prev)
            tmp_b = tmp_b->prev;
    }
	while(tmp_a)
	{
		tmp_a->index = i++;
		tmp_a = tmp_a->next;
	}
	i = 0;
	while(tmp_b)
	{
		tmp_b->index = i++;
		tmp_b = tmp_b->next;
	}
}

void cost_stack(ps_lst *stack)
{
    ps_lst  *tmp;
    
    if (!stack)
        return ;
    tmp = stack;
    while(tmp)
    {
        if(tmp->index == 0)
            tmp->cost = 0;
        else if(tmp->index == 1)
            tmp->cost = tmp->index;
        else if((tmp->index - 1) <= (ps_size(tmp) - tmp->index))
            tmp->cost = tmp->index;
        else if((tmp->index - 1) > (ps_size(tmp) - tmp->index))
            tmp->cost = ps_size(stack) - tmp->index;
        tmp = tmp->next;
    }
}

ps_lst *more_cheap(ps_lst *stack)
{
    ps_lst *cheap_node;
    ps_lst *tmp;
    
    if(!stack)
        return (NULL);
    tmp = stack;
    cheap_node = stack;
    while(tmp)
    {
        if((tmp->cost + tmp->target->cost) < (cheap_node->cost + cheap_node->target->cost))
            cheap_node = tmp;
        tmp = tmp->next;
    }
    return (cheap_node);
}

void make_moviment(ps_lst **stack_a, ps_lst **stack_b)
{
    ps_lst *tmp;
    
    tmp = more_cheap(*stack_a);
    while (tmp->index != 0)
    {
        if ((tmp->index) <= (ps_size(tmp) - tmp->index) && (tmp->index == tmp->target->index))  
            rr(stack_a, stack_b);
        else if ((tmp->index) <= (ps_size(tmp) - tmp->index))  
            ra(stack_a);
        else if ((tmp->index) > (ps_size(tmp) - tmp->index) && (tmp->index == tmp->target->index))  
            rrr(stack_a, stack_b);
        else if ((tmp->index) > (ps_size(tmp) - tmp->index))
            rra(stack_a);
        redefine_index(tmp, tmp->target);
    }
    while (tmp->target->index != 0)
    {
        if ((tmp->target->index - 1) <= (ps_size(tmp->target) - tmp->target->index))  
            rb(stack_b);
        else if ((tmp->target->index - 1) > (ps_size(tmp->target) - tmp->target->index))
            rrb(stack_b);
        redefine_index(tmp, tmp->target);
    }
    pb(stack_a, stack_b);
}

void ordering(ps_lst **stack_a, ps_lst **stack_b)
{
    ps_lst *tmp;

    tmp = ps_soon_bigest(*stack_a, *stack_b);
    while (tmp->index != 0)
    {
        if ((tmp->index) <= (ps_size(tmp) - tmp->index))  
            ra(stack_a);
        else if ((tmp->index) > (ps_size(tmp) - tmp->index))
            rra(stack_a);
        redefine_index(tmp, tmp->target);
    }
    pa(stack_b, stack_a);
}

int main(void)
{
    int args[] = {321, 322, 19, 432, 374, 191, 183, 31, 459, 53, 79, 424, 283, 47, 164, 199, 156, 440, 123, 400, 267, 367, 452, 166, 398, 229, 297, 155, 227, 482, 147, 20, 209, 280, 203, 149, 15, 247, 99, 317, 140, 104, 332, 326, 306, 495, 33, 81, 337, 159, 289, 480, 37, 270, 125, 95, 13, 223, 40, 4, 67, 383, 221, 204, 413, 248, 354, 258, 24, 486, 243, 348, 375, 69, 411, 330, 307, 303, 302, 493, 469, 56, 372, 245, 3, 491, 328, 193, 194, 279, 350, 378, 42, 403, 450, 17, 262, 369, 394, 177, 410, 90, 16, 359, 414, 61, 94, 246, 240, 471, 313, 82, 50, 72, 311, 436, 264, 112, 453, 395, 118, 251, 365, 455, 190, 206, 239, 430, 490, 172, 169, 444, 487, 136, 196, 168, 358, 500, 212, 366, 310, 377, 392, 301, 445, 249, 102, 298, 293, 109, 339, 399, 228, 470, 406, 294, 238, 488, 255, 477, 167, 14, 182, 281, 296, 308, 386, 207, 388, 396, 114, 80, 70, 124, 106, 217, 138, 133, 152, 5, 346, 397, 26, 65, 165, 161, 59, 304, 460, 492, 483, 142, 7, 158, 32, 290, 352, 473, 331, 305, 338, 295, 253, 463, 232, 189, 420, 62, 110, 443, 439, 384, 336, 389, 1, 250, 89, 108, 210, 218, 344, 385, 320, 288, 418, 285, 129, 341, 468, 185, 39, 405, 163, 271, 2, 237, 63, 9, 186, 315, 100, 334, 141, 66, 200, 170, 465, 154, 236, 474, 276, 48, 128, 143, 192, 266, 92, 259, 148, 8, 466, 464, 68, 349, 244, 273, 197, 323, 309, 438, 144, 481, 225, 226, 54, 96, 268, 122, 195, 103, 224, 363, 390, 379, 449, 85, 454, 373, 157, 252, 476, 116, 27, 431, 88, 45, 387, 131, 121, 201, 175, 52, 178, 423, 241, 162, 497, 429, 75, 275, 139, 416, 357, 87, 208, 408, 117, 35, 36, 132, 115, 499, 60, 230, 376, 73, 74, 256, 496, 57, 233, 425, 11, 222, 299, 180, 286, 126, 434, 404, 345, 151, 472, 44, 435, 393, 353, 335, 479, 485, 382, 265, 437, 184, 91, 355, 98, 461, 327, 362, 97, 340, 319, 329, 134, 407, 312, 41, 441, 46, 428, 333, 422, 260, 101, 364, 446, 426, 391, 314, 412, 220, 342, 300, 216, 174, 484, 198, 318, 356, 261, 421, 478, 111, 187, 171, 77, 467, 360, 76, 433, 494, 202, 402, 231, 120, 351, 160, 38, 113, 370, 257, 29, 451, 442, 361, 176, 277, 368, 343, 381, 146, 145, 137, 34, 211, 107, 6, 462, 12, 269, 292, 173, 43, 371, 254, 78, 415, 23, 282, 153, 150, 58, 119, 324, 447, 93, 22, 489, 417, 10, 215, 274, 105, 325, 234, 130, 498, 235, 278, 55, 448, 25, 64, 84, 213, 83, 380, 457, 427, 179, 272, 49, 409, 188, 135, 284, 401, 127, 347, 475, 419, 181, 86, 316, 291, 214, 263, 456, 28, 242, 205, 18, 51, 21, 71, 219, 458, 287, 30};
    int size = sizeof(args) / sizeof(args[0]);
    ps_lst *stack_a = NULL;
    ps_lst *stack_b = NULL;
    add_args(&stack_a, args, size);
    pb(&stack_a, &stack_b);
    pb(&stack_a, &stack_b);
    if(stack_b->num != ps_bigest(stack_b)->num)
        sa(&stack_b);
    redefine_index(stack_a, stack_b);
    ps_target(stack_a, stack_b);
    cost_stack(stack_a);
    cost_stack(stack_b);
    while(ps_size(stack_a) != 3)
    {
        make_moviment(&stack_a, &stack_b);
        redefine_index(stack_a, stack_b);
        cost_stack(stack_a);
        cost_stack(stack_b);
        ps_target(stack_a, stack_b);
    }
    
    while((ps_bigest(stack_b)->index != 0))
    {
        rrb(&stack_b);
        redefine_index(stack_a, stack_b);
    }

    while((ps_bigest(stack_b)->index != 0))
    {
        rrb(&stack_b);
        redefine_index(stack_a, stack_b);
    }
    
    while((ps_size(stack_b) != 1))
    {
        ordering(&stack_a, &stack_b);
        redefine_index(stack_a, stack_b);
    }
    pa(&stack_b, &stack_a);
    ps_free_all(stack_a);
    ps_free_all(stack_b);
    return (0);
}

